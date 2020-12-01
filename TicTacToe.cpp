#include<iostream>
#include<vector>
using namespace std;


int N;//size of table
char c;//if c=='x', player is first, if c=='o', AI is first
//'x' is maximizer, 'o' is minimizer
struct Table
{
private:
    char table[10][10];
public:

    Table()
    {
        for(int i= 0; i<N; i++)
            for(int j=0; j<N; j++)
                table[i][j] = '*';
    }

    char getCell(int i, int j)
    {
        return table[i][j];
    }

    void setCell(int i, int j, char c)
    {
        table[i][j] = c;
    }
    bool isFull()
    {
        for(int i = 0; i<N; i++)
        {
            for (int j = 0; j<N; j++)
                if(table[i][j]=='*')
                    return false;
        }
        return true;
    }

    void print()
    {
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int winnerValue(char v)
    {
        switch(v)
        {
        case 'x':
            return 1;
            break;
        case 'o':
            return -1;
            break;
        default:
            return 0;
        }
    }

    int checkForWinner()
    {
        char element;
        bool win;
        //check rows
        for(int i = 0; i<N; i++)
        {
            element = table[i][0];
            if(element == '*')
                continue;
            win = true;

            for(int j = 0; j<N; j++)
            {
                if(table[i][j] != element)
                {
                    win = false;
                    break;
                }
            }
            if(win)
                return winnerValue(element);
        }
        //check columns
        for(int i = 0; i<N; i++)
        {
            element = table[0][i];
            if(element == '*')
                continue;
            bool win = true;

            for(int j = 0; j<N; j++)
            {
                if(table[j][i] != element)
                {
                    win = false;
                    break;
                }
            }
            if(win)
                return winnerValue(element);
        }

        //check main diagonal
        element = table[0][0];
        win = true;
        for(int i = 0; i<N; i++)
        {
            if(table[i][i]!=element)
            {
                win = false;
                break;
            }
        }
        if(win)
            return winnerValue(element);

        //check minor diagonal
        element = table[0][N-1];
        win = true;
        for(int i = 0; i<N; i++)
        {
            if(table[i][N-i-1]!=element)
            {
                win = false;
                break;
            }
        }
        if(win)
            return winnerValue(element);

        return 0;
    }

    void makeMove(){
        if(!isFull()){
            char moveCoor[10];
            cout<<"Write you move like: [i,j], where i is the row and j is the column: ";
            cin>>moveCoor;
            int row = moveCoor[1]-'0';
            int col = moveCoor[3]-'0';
            if(c == 'x')
                table[row-1][col-1] = 'x';
            else if (c=='o')
                table[row-1][col-1] = 'o';
        }
    }

    void init()
    {
        for(int i = 0; i<N; i++)
            for(int j = 0; j<N; j++)
                cin>>table[i][j];
    }

};


int minimax(Table& state,bool isMaximizer, int alpha, int beta)
{
    int result = state.checkForWinner();
    if(result == 1 || result == -1) return result;
    if(state.isFull()) return 0;

    if(isMaximizer)
    {
        int bestScore = -1000;
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(state.getCell(i,j) == '*')
                {
                    state.setCell(i,j,'x');
                    int score = minimax(state,false, alpha, beta);
                    state.setCell(i,j,'*');
                    if(score > bestScore)
                    {
                        bestScore = score;
                    }
                    if(bestScore >= beta) return bestScore;
                    alpha = max(alpha, bestScore);
                }
            }

        }
        return bestScore;

    }
    else
    {
        int bestScore = 1000;
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(state.getCell(i,j) == '*')
                {
                    state.setCell(i,j,'o');
                    int score = minimax(state,true, alpha, beta);
                    state.setCell(i,j,'*');
                    if(score < bestScore)
                    {
                        bestScore = score;
                    }
                    if(bestScore <= alpha) return bestScore;
                    beta = min(beta, bestScore);
                }
            }

        }
        return bestScore;
    }

}

//here AI makes his decision for his next move
void MiniMaxDecision(Table &state)
{
    if(c=='o') //AI is maximizer
    {
        int bestScore = -1000;
        pair<int,int> bestMove;

        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(state.getCell(i,j) == '*')
                {
                    state.setCell(i,j,'x');
                    int score = minimax(state, false, -100, 100);
                    state.setCell(i,j,'*');
                    if(score >bestScore)
                    {
                        bestScore = score;
                        bestMove.first = i;
                        bestMove.second = j;
                    }

                }
            }

        }
        state.setCell(bestMove.first,bestMove.second,'x');
    }
    else if(c=='x') //AI is minimizer
    {
        int bestScore = 1000;
        pair<int,int> bestMove;

        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(state.getCell(i,j) == '*')
                {
                    state.setCell(i,j,'o');
                    int score = minimax(state, true,-100,100);
                    state.setCell(i,j,'*');
                    if(score < bestScore)
                    {
                        bestScore = score;
                        bestMove.first = i;
                        bestMove.second = j;
                    }

                }
            }

        }
        state.setCell(bestMove.first,bestMove.second,'o');
    }

}


void solve()
{
    cout<<"Size of table: ";
    cin>>N;
    Table t;
    t.print();
    cout<<"Are you playing with X or O? (x/o)"<<endl;

    cin>>c;
    if(c == 'x'){
        t.makeMove();
        t.print();
    }

    int winner = 0;
    while(!t.isFull()){
       MiniMaxDecision(t);
       t.print();
       winner = t.checkForWinner();
       if(winner != 0) break;
       t.makeMove();
       winner = t.checkForWinner();
       if(winner != 0) break;
    }
    cout<<endl;
    if(winner == 1) cout<<"X won!"<<endl;
    if(winner == -1) cout<<"O won!"<<endl;
    if(winner == 0) cout<<"Tie!"<<endl;
}


int main()
{
    solve();
    return 0;
}

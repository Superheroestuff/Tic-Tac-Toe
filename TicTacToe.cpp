#include<iostream>
#include<vector>
using namespace std;


int N;//size of table
char c;//if c=='x', player is first, if c=='o', AI is first
//'x' is maximizer, 'o' is minimizer
struct Table
{
private:
    char** table; //a table NxN filled with 0
public:

    Table()
    {
        table = new char*[N];
        for(int i = 0; i<N; i++)
        {
            table[i] = new char[N];
        }

        for(int i= 0; i<N; i++)
            for(int j=0; j<N; j++)
                table[i][j] = '*';

    }

    char getCell(int i, int j){
        return table[i][j];
    }

    void setCell(int i, int j, char c){
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
    int winnerValue(char v){
        switch(v){
            case 'x': return 1;
            break;
            case 'o': return -1;
            break;
            default: return 0;
        }
    }

    int checkForWinner(){
        char element;
        bool win;
        //check rows
        for(int i = 0; i<N; i++){
            element = table[i][0];
            if(element == '*') continue;
            win = true;

            for(int j = 0; j<N;j++){
                if(table[i][j] != element){
                    win = false;
                    break;
                }
            }
            if(win) return winnerValue(element);
        }
        //check columns
        for(int i = 0; i<N; i++){
            element = table[0][i];
            if(element == '*') continue;
            bool win = true;

            for(int j = 0; j<N;j++){
                if(table[j][i] != element){
                    win = false;
                    break;
                }
            }
            if(win) return winnerValue(element);
        }

        //check main diagonal
        element = table[0][0];
        win = true;
        for(int i = 0; i<N; i++){
            if(table[i][i]!=element){
                win = false;
                break;
            }
        }
        if(win) return winnerValue(element);

        //check minor diagonal
        element = table[0][N-1];
        win = true;
        for(int i = 0; i<N; i++){
            if(table[i][N-i-1]!=element){
                 win = false;
                break;
            }
        }
        if(win) return winnerValue(element);

        return 0;
    }

    void init(){
        for(int i = 0; i<N;i++)
            for(int j = 0; j<N;j++)
                cin>>table[i][j];
    }

};

//here AI makes his decision for his next move
void MiniMaxDecision(Table &state)
{
    if(c=='x') //AI is maximizer
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
                    int score = 0;
                    //int score = minimax(state, 0, true);
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
    else if(c=='o') //AI is minimizer
    {

    }

}

int minimax(Table& state,int depth,bool isMaximizer){
    //if(checkWhoWins)
    //return -1,0 or +1;
    if(isMaximizer){

    }

}



void solve()
{
    cout<<"Size of table: ";
    cin>>N;
    Table t;
    t.print();
    //cout<<"Do you want to be first? (y/n)"<<endl;

    //cin>>c;
    //if(c=='y')
    //else if(c=='n')

}


int main()
{
    N=3;
    Table t;
    t.init();
    t.print();
    cout<<t.checkForWinner();
    //solve();


    return 0;
}

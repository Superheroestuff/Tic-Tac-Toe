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
                if(state[i][j] == '*')
                {
                    state[i][j] = 'x';
                    int score = minimax(state, 0, true);
                    state[i][j] = '*'
                    if(score >bestScore)
                    {
                        bestScore = score;
                        bestMove.first = i;
                        bestMove.second = j;
                    }

                }
            }

        }
        state[bestMove.first][bestMove.second] = 'x';
    }
    else if(x=='o') //AI is minimizer
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
    solve();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct Student{
   long long a;
   char c;
}maze[10000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,k=0,x;
    char y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>maze[i].a>>maze[i].c;
    }
    int l=1;
    int r=n;
    while(1){
        if(l>=r){
            break;
        }
        if(maze[l].c!=maze[r].c){
            if(maze[l].a>maze[r].a)
            {
                k+=maze[r].a;
                maze[l].a=maze[l].a-maze[r].a;
                r--;
            }
            else if(maze[l].a<maze[r].a)
            {
                k+=maze[l].a;
                maze[r].a=maze[r].a-maze[l].a;
                l++;
            }
            else if(maze[l].a==maze[r].a){
                k+=maze[l].a;
                l++;
                r--;
            }
        }
        else if(maze[l].c==maze[r].c){
            if(maze[l].a>maze[r].a)
            {
                maze[l].a=maze[l].a-maze[r].a;
                r--;
            }
            else if(maze[l].a<maze[r].a)
            {
                maze[r].a=maze[r].a-maze[l].a;
                l++;
            }
            else if(maze[l].a==maze[r].a){
                l++;
                r--;
            }
        }
    }
    cout<<k;
    return 0;
}

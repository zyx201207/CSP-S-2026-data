#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[500005]={0};
int game[500005];
int pos=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //4 3
    //1 2 1 3
    //pos=3
    //game=1,2
    for(int i=1;i<=n;i++){
        pos=1;
        for(int j=i;j<=n;j++){
            for(int fd=1;fd<pos;fd++){
                if(game[fd]==a[j]){
                    pos=fd;
                    break;
                }
            }
            game[pos]=a[j];
            pos++;
            //cout<<i<<' '<<j<<' '<<pos<<endl;
            //for(int m=1;m<pos;m++)cout<<game[m]<<' ';
            //cout<<endl;
        }
        for(int j=1;j<pos;j++){
            ans[game[j]]++;
        }
        //for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
	return 0;
}

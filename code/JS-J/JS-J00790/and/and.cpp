#include <iostream>

using namespace std;

int n,m;

int a[2000000];

bool e[21];

int max;

void dfs(int v,int y){
    if(v==n){

        int sum=1<<20-1;

        for(int i=0;i<n;i++){

            if(e[i])sum=sum&a[i];

        }

        max=max(max,sum;);

        return ;
    }
    dfs(v+1,y);

    if(y){

        e[v++]=true;

        dfs(v,y-1);

    }

    return ;
}

int main()
{
    cin>>n>>m;

    if(n==m){
        int ans;

        for(int i=0;i<n;i++){

            int in;

            cin>>in;

            ans=ans&in;

        }

        cout<<ans;

        return 0;
    }
    if(m==1){
        int in;

        for(int i=0;i<n;i++){

            cin>>in;

            max=max(max,in);

        }

        cout<<max;

        return 0;

    }
    if(m==2){

        for(int i=0;i<n;i++){
            cin>>a[i];
            for(int j=0;j<i;j++)max=max(max,a[i]&a[j]);
        }

        cout<<max;

        return 0;
    }
    for(int i=0;i<n;i++){

        cin>>a[i];

    }

    dfs(0,m);

    cout<<max;

    return 0;
}

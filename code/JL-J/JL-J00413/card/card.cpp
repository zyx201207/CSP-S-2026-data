#include<bits/stdc++.h>
using namespace std;
int a,b,c[500005],d[500005]={0};
stack<int> s;
int s1[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i = 1;i<=a;i++){
        cin>>c[i];
    }
    int yu=1;
    for(int i = 1;i<=a;i++){

            for(int u = i;u<=a;u++){

                for(int j = 1;j<yu;j++){
                    if(s1[j]==c[u]){
                        while(s.top()!=c[u]){
                            s.pop();

                        }
                        s.pop();
                    }
                }
                s.push(c[u]);
                s1[yu]=c[u];
                yu++;
            }
            while(!s.empty()){
                d[s.top()]++;
                s.pop();
            }


    }
    for(int i = 1;i<=b;i++){
        cout<<d[i]<<endl;
    }
    return 0;
}

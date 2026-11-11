#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[300010],ans[300010],o,p;
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        for(int z=1;z<=m;z++){
            t[z]=0;
        }
        for(int j=i;j<=n;j++){
            if(t[a[j]]==0){
                s.push(a[j]);
                t[a[j]]=1;
            }else{
                 while(1){
                    o=s.top();
                    s.pop();
                    t[o]=0;
                    if(o==a[j])break;
                 }s.push(a[j]);
            }
        }while(!s.empty()){
            p=s.top();
            s.pop();
            ans[p]++;
        }
    }for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
	return 0;
}

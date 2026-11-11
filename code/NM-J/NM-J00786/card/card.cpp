//Trick||Treat!
#include<bits/stdc++.h>
#define LL long long
using namespace std;
bool flag[300005];
int out[300005],n,m,a[500005];
int main(){
	//freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    stack<int> s;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    	scanf("%d",&a[i]);
    for(int i=1;i<=n;++i){
    	for(int j=i;j<=n;++j){
    		if(flag[a[j]]){
    			while(s.top()!=a[j]){
    				flag[s.top()]=0;
    				s.pop();
				}
				s.pop();
			}
			else{
				flag[a[j]]=1;
			}
			s.push(a[j]);
		}
		stack<int> f;
		while(!s.empty()){
			out[s.top()]++;f.push(s.top());s.pop();
		}
		while(!f.empty()){
			s.push(f.top());f.pop();
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d ",out[i]);
	}
	return 0;
} 

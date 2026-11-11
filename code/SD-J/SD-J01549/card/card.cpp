#include<bits/stdc++.h>
using namespace std;
stack<int> t;
int n,m;
const int N=5e5+10;
const int M=3e5+10;
int cards[N];
int l[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>cards[i];
    for(int i=1;i<=n;i++){
    	bool c[M];
    	memset(c,0,sizeof c);
    	for(int j=i;j<=n;j++){
    	    int ca=cards[j];
    	    if(c[ca]){
    	    	while(t.top()!=ca) {
    	    		c[t.top()]=0;
    	    	    t.pop();	
				}
			}
			else{
				t.push(ca);
				c[ca]=1;
			}
		}
	    for(int i=0;i<=m;i++) if(c[i]) l[i]++;
	}
	for(int i=1;i<=m;i++) cout<<l[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}


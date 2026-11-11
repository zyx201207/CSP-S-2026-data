#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];

int c[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int qqq=n;
	int ii=0;
	while(qqq--){
		
		for(int i=1;i<=m;i++){
			c[i]=0;
		}
		ii++;
		queue <int> s;//s±¾ÅÄ¾ç µÄÅÄ   b×ÀÃæ
		stack <int> b; 
		for(int i=ii;i<=n;i++){
			s.push(a[i]);
		}
		while(!s.empty()){
			if(c[s.front()]!=0){
				
				while(!b.empty()){
					c[b.top()]--;
					if(b.top()==s.front()){
						b.pop();
						break;
					}else{
						b.pop();
					}
				}
			}
			b.push(s.front());
			c[s.front()]++;
			s.pop();
			
		}
		while(!b.empty()){
			d[b.top()]++;
			b.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool b[1000005];
int a[1000005];
int c[1000005];
stack <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int u=1;u<=n;u++){
		for(int i=1;i<=m;i++){
			b[i]=0;
			if(!s.empty())
				s.pop();
		}
		for(int i=u;i<=n;i++){
			if(!b[a[i]]){
				s.push(a[i]);
				b[a[i]]=1;
				c[a[i]]++;
			}
			else{
				while(!s.empty()){
					if(s.top()==a[i])
				  	  break;
					c[s.top()]--;
					b[s.top()]=0;
					s.pop();
				}
			}
		}
    }
	for(int i=1;i<=m;i++)
		cout<<c[i]<<' ';
	return 0;
}

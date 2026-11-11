#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],b[300005];
stack<int> s,s1,s2;
bool f1,f2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f1=0;
		    while(!s.empty()){
		    	s1.push(s.top());
		    	if(s.top()==a[j]) f1=1;
		    	s.pop();
			}
			while(!s1.empty()){
				s.push(s1.top());
			//	cout<<s1.top()<<endl;
				s1.pop();
			}
			if(!f1) s.push(a[j]);
			else{
				while(s.top()!=a[j]) s.pop();
			}
		}
		for(int i=1;i<=m;i++){
			f2=0;
			while(!s.empty()){
				s2.push(s.top());
				if(s.top()==i) f2=1;
				s.pop();
			}
			while(!s2.empty()){
				s.push(s2.top());
			//	cout<<s2.top()<<' ';
				s2.pop();
			}
			if(f2) b[i]++;
		}
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}

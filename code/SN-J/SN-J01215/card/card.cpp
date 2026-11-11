#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n,m,a[N],t[N];
bool in[N];
stack<int> s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int c=1;c<=n;c++)
	{
//	cout<<endl;
		for(int i=1;i<=m;i++) in[i]=0;
		for(int i=c;i<=n;i++)
		{
			if(in[a[i]]){
				while(1)
				{
					int lls=s.top();
//		cout<<"***"<<lls<<" ";
					if(lls==a[i]) break;
					in[lls]=0;
//		cout<<"-"<<lls<<" ";
					s.pop();
				 }
				in[a[i]]=1;
//		cout<<"-"<<a[i]<<' ';
			}
			else{
				s.push(a[i]);
//		cout<<a[i]<<" ";
				in[a[i]]=1;
			}
		}
		while(!s.empty()){
			int dap=s.top();
			s.pop();
			t[dap]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
4 3
1 2 1 3
5 3 
1 2 1 3 2
*/

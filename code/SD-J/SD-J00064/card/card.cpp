#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,top;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n+5);
	vector<int> st(n+5);
	vector<int> ans(m+5);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=top;k++){
				if(st[k]==a[j]){
					top=k-1;
					break;
				}
			}
			st[++top]=a[j];
		}
		for(int j=1;j<=top;j++){
			ans[st[j]]++;
		}
		top=0;
	}
	for(int i=1;i<m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[m];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int t[500100];
int c[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,k,f=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]) f++;
	}
	if(n<=5000){
		stack<int>s;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				t[a[j]]++;
				if(t[a[j]]==2){
					while(s.top()!=a[j]){
						t[s.top()]--;
						s.pop();
					}
					s.pop();
					t[a[j]]=1;
				}
				s.push(a[j]);
			}
			for(int j=1;j<=k;j++){
				if(t[j]!=0) c[j]++;
				t[j]=0;
			}
			while(!s.empty()) s.pop();
		}
		for(int i=1;i<=k;i++) cout<<c[i]<<" ";
	}
	else{
		if(f==n){
			for(int i=1;i<=n;i++) c[a[i]]=i;
			for(int i=1;i<=k;i++) cout<<c[i]<<" ";
		}
		else if(k==1) cout<<n;
	}
	return 0;
} 

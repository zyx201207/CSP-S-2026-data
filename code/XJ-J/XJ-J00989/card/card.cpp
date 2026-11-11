#include<bits/stdc++.h>
using namespace std;
stack <int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s[m+5];
	for(int i=1;i<=n;i++){
		s[a[i]]++;
	}
	int w[m+5];
	for(int i=1;i<=m;i++){
		w[i]=0;
	}
	for(int i=1;i<=m;i++){
		if(s[i]>1){
			w[i]=1;
		}
	}
	int b[n+5];
	int k=1;
	int num[m+5];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(w[i]==1){
				while(q.top()!=a[j]&&q.empty()!=0){
				b[k]=q.top();
				q.pop();
				k++;
				}
				if(q.top()==a[j]){
					q.pop();
					q.push(a[j]);
				}
				else if(q.empty()==0){
					for(int l=k;l>=1;l--){
						q.push(b[l]);
					}
				}
			}
			else{
				q.push(a[j]);
			}
		}
		while(q.empty()!=0){
			int t=q.top();
			num[t]++;	
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
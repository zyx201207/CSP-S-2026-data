#include<bits/stdc++.h>
using namespace std;
long long a[300000];
long long ans[300000];
long long used[300000];
long long n,m;
long long h,l,flag=0,r;
stack<long long> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>> n >> m;
    for(long long i=1;i<=n;i++){
		cin>> a[i];
		if(a[i]<a[i-1]){
			flag=1;
		}
	}
	if(flag==0){
		a[n+1]=0;
		for(long long i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				ans[a[i]]=i;
			}
		}
		for(long long i=1;i<=m;i++){
			cout<< ans[i] << ' ';
		}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			used[j]=0;
		}
		for(long long j=i;j<=n;j++){
			if(st.empty()){
				st.push(a[j]);
				used[a[j]]++;
			}
			else{
				if(used[a[j]]==0){
					st.push(a[j]);
					used[a[j]]++;
				}
				else{
					while(!st.empty() && st.top()!=a[j]){
						used[st.top()]--;
						st.pop();
					}
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			//cout<< st.top() << ' ';
			st.pop();
		}
		//cout<<endl;
	}
	for(long long i=1;i<=m;i++){
		cout<< ans[i] << ' ';
	}
    return 0;
}

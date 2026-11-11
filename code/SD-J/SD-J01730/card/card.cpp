#include<bits/stdc++.h> 
#define ll long long
using namespace std;
ll a[200005],ans,n,k,tong[200005];
ll t2[200005];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int i=1;i<=k;++i){
			t2[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(t2[a[j]]==0){
				st.push(a[j]);
				t2[a[j]]++;
			}
			else{
				while(t2[a[j]]){
					t2[st.top()]--;
					st.pop();
				}
				st.push(a[j]);
				t2[a[j]]=1;
			}
		}
		for(int j=1;j<=k;j++){
			tong[j]+=t2[j];
		}
	}
	for(int j=1;j<=k;j++){
		cout<<tong[j]<<" ";
	}
	return 0;
}

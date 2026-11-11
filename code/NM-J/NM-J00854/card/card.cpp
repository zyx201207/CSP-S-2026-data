#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int b[2000001];
int n,m;
int cnt[3];
void d(int k){
	if(k>n) return;
	if(a[k]==a[n]){
		cnt[a[k]]++;
	}else{
		cnt[1]++,cnt[2]++;
	}
	d(k+1);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==1){
		cout<<n;
		return 0;
	}
	d(1);
	cout<<cnt[1]<<" "<<cnt[2];
	return 0;
} 

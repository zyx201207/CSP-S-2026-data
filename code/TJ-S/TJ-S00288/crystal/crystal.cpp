#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long cha[N],a[N];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	 cin>>n>>m;
	 for(int i = 1;i <= n;i++){
	 	cin>>a[i];
	 	cha[i] = a[i] - a[i - 1];
	
	 }
	 long long mx = -1e9;
	 for(int i = 1;i <= n;i++){
	 	long long m_ = m,ch = 0,cal = 0;
	 	for(int k = i;k > 1;k--){
	 		ch += cha[i];
	 		if(m_ - ch >= 0)m_ -= ch,cal++;
		 }
		 mx = max(mx,cal);
	 }
	 cout<<mx + 1;
} 



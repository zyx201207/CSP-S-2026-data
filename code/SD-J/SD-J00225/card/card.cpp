#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,q[500005];
bool cha(){
	for(long long i = 1;i < n;i ++){
		if(a[i] > a[i+1]) return 0;
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i <= n;i ++) cin>>a[i];
	if(m==2){
		for(long long i = 1;i <= n;i ++){
			if(a[i] == a[n]) q[a[n]] ++;
			else q[1] ++,q[2] ++;
		}
		cout<<q[1]<<" "<<q[2]<<"\n";
		return 0;
	}
	else if(cha()){
		for(long long i = 2;i <= n;i ++){
			if(a[i] != a[i-1]) q[a[i]-1] = i-1;
		}
		q[m] = n;
		for(long long i = 1;i <= m;i ++) cout<<q[i]<<" ";
		return 0;
	}
	else{
		for(long long i = 1;i <= m;i ++){
			for(long long j = n;j >= 1;j --){
				if(a[j] == i){
					q[i] = j;
					break;
				}
			}
		}
		for(long long i = 1;i <= m;i ++){
			cout<<q[i]<<' ';
		}
	}
	return 0;
}

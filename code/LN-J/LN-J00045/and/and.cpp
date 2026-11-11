#include<bits/stdc++.h>
using namespace std;
int n,m,at,b[200000];
bool a[200000],Max[31],Ans[31],T[31];
void tobool(int x,int y){
	int t=0;
	while(x>0){
		++t;
		a[y][t]=x%2;
		if(a[y][t]==1) b[y]++;
		x/=2;
	}
	return;
}
int ans(int x){
	int t=0;
	for(int i=1;i<=31;i++){
		while(a[1]>0){
			++t;
			Ans[t]=a[1]%2;
			a[1]/=2;
		}
		for(int j=2;j<=m;j++){
			while(a[j]>0){
				++t;
				T[t]=a[j]%2;
				a[j]/=2;
			}
			for(int k=1;k<=31;k++){
				Ans[k]=Ans[k]&T[k];
			}
		}
	}
	for(int i=31;i>=1;i--){
		if(Ans[i]==)
	}
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>at;
		tobool(at,i);
		for(int j=i;j>=2;j--){
			if(b[j]>b[j-1]){
				swap(b[j],b[j-1]);
				swap(a[j],a[j-1]);
			}
		}
	}
	cout<<a[1];
	return 0;
}

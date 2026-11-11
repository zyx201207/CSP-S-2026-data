#include<bits/stdc++.h>
using namespace std;
long long n,m,s,i,j,a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
	}
	else{
		sort(a,a+n,cmp);
		s=a[0];
		for(i=1;i<m;i++){
			s&=a[i];
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
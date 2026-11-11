#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],maxx,p,m2,A[2000005],n1[2000004],ans;
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		m2=0;
		p=a[i];
		while(p!=0){
			m2++;
			if(p%2!=0){
				s[i]+="1"; 
				n1[i]++;
			}else{
				s[i]+="0";
				n1[i]++;
			}
			p/=2;
		}
	}
	for(int i=n;i>=1;i--){
		int sum1=i;
		maxx=a[i];
		while((i-sum1)<=m){
			if(n1[sum1]==n1[sum1-1]){
				maxx=(a[sum1]&maxx);
				sum1--;
			}else{
				if(maxx<(a[sum1]&a[sum1-1])){
					maxx=(a[sum1]&maxx);
					sum1--;
				}else{
					ans=max(maxx,ans);
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}



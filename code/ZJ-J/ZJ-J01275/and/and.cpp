#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[10];
bool flag,flag1,flag2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0||a[i]==1||a[i]==3||a[i]==7||a[i]==15||a[i]==31||a[i]==63||a[i]==127||a[i]==255||a[i]==511||a[i]==1023||a[i]==2047||a[i]==4095||a[i]==8191||a[i]==16383||a[i]==32767||a[i]==65535||a[i]==131071||a[i]==262143||a[i]==524287||a[i]==1048575){
			
		}
		else{
			flag=1;
		}
		if(a[i]!=(i-1)){
			flag1=1;
		}
		else{
			
		}
		if(a[i]>4){
			flag2=1;
		}
	}
	if(m==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			int cm=(a[i] and (int)0);
			cnt=max(cnt,cm);
		}
		cout<<cnt;
		return 0;
	}
	if(m==2){
		int cnt1=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int mx=(a[i] and a[j]);
				cnt1=max(cnt1,mx);
			}
		}
		cout<<cnt1;
		return 0;
	}
	if(m==n){
		int k=(a[1] and a[2]);
		for(int i=3;i<=n;i++){
			k=(k and a[i]);
		}
		cout<<k;
		return 0;
	}
	if(flag==0){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if(flag1==0){
		sort(a+1,a+1+n);
		if(m%2==1){
			cout<<a[n-m];
		}
		else{
			cout<<a[n-m+1];
		}
		return 0;
	}
	if(flag2==0){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		if(m<=b[4]){
			cout<<"4";
			return 0;
		}
		m-=b[4];
		if(m<=(b[1]+b[3])){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}
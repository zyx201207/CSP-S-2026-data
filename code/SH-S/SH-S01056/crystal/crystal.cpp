#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[5000001]={};
long long b[5000001]={};
long long anns=0;
int ok(){
	for(int i=1;i<=n-2;i++){
		if(a[i+2]-a[i+1]!=a[i+1]-a[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(ok()==1){
		int qw=a[2]-a[1];
		int as=qw;
		int er=m;
		int ty=n-1;
		int ui=1;
		int op=0;
		while(er>=qw&&ty>0){
			ui++;
			op++;
			er-=qw;
			ty--;
			if(op==2){
				qw+=as;
				op=0;
			}
		}
		cout<<ui;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[j]=a[i]-a[j];
		}
		sort(b+1,b+1+i);
		/*for(int j=1;j<=i;j++){
			cout<<b[j]<<" ";
		}
		cout<<endl;*/
		long long ans=0,num=1,cnt=m;
		while(num<=i&&cnt>0){
			
			if(cnt>=b[num]&&b[num]>=0){
				ans++;
				cnt-=b[num];
			}
			else if(cnt<b[num]){
				break;
			}
			num++;
		}
		//cout<<ans<<endl;
		anns=max(ans,anns);
	}
	cout<<anns;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

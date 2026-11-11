#include<bits/stdc++.h>
using namespace std;
int a[4]={0,0,0};
int s[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>s[i];
	int cnt1=0,cnt2=0;
	for(int k=1;k<=n;k++){
		bool flag1=false;
		bool flag2=false;
		for(int i=k;i<=n;i++){
			if(s[i]==1) flag1=true;
			if(s[i]==2) flag2=true;
		}
		for(int j=1;j<=n;j++){
			if(flag1) cnt1++;
			if(flag2) cnt2++;
		}
	}
	cout<<cnt1/n<<' '<<cnt2/n<<endl;
	return 0;
}

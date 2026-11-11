#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
long long sv1012[210];

long long sv_10_12(){
	for(long long i=1;i<=n;i++){
		a[i]+=100;
	}
	for(long long i=1;i<=n;i++){
		if(a[i]<0||a[i]>200)continue;
		sv1012[a[i]]++;
	}
	/*for(long long i=0;i<=200;i++){
		cout<<i<<':'<<' '<<sv1012[i]<<'\n';
	}*/
	long long res=0;
	for(long long i=200;i>=0;i--){
		res=max(res,ans);
		ans=sv1012[i];
		long long mm=m;
		//cout<<mm<<' ';
		for(long long j=i-1;j>=0;j--){
			//cout<<mm<<' ';
			if(mm==0)break;
			if(mm>=sv1012[j]*(i-j)){
				ans+=sv1012[j];
				mm-=(sv1012[j]*(i-j));
				continue;
			}
			ans+=(mm/(i-j));
			break;
		}
		res=max(res,ans);
		//cout<<ans;
		//cout<<endl;
	}
	return res;
}


long long sv_nm(){
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		if(a[i]==a[i+1]) continue;
		long long mm=m;
		for(long long j=i-1;j>=1;j--){
			if(a[i]-a[j]>mm){
				ans=max(ans,i-j);
				break;
			}
			mm-=(a[i]-a[j]);
			if(j==1){
				return (i-j+1);
			} 
		}
		
	}
	return ans;
}


long long svA(){
	long long ans=0;
	for(long long i=1;m>=0;i++){
		ans++;
		m-=i;
	}
	return min(ans,n);
}


long long svB(){
	long long kkk=a[2]-a[1];
	long long ans=0;
	for(long long i=1;m>=0&&ans<=n;i++){
		ans++;
		m-=i*kkk;
	}
	return min(ans,n);
}



int main(){
	//freopen()
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag1012=1,flagA=1,flagB=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>100||a[i]<-100) flag1012=0;
		if(i!=a[i]) flagA=0;
		if(i>=3&&a[i]+a[i-2]!=a[i-1]*2) flagB=0;
	}
	if(n<=5010&&m<=1e9+10){
		cout<<sv_nm();
	}
	else if(n>5010&&flag1012){
		cout<<sv_10_12();
	}
	else if(m>1e9&&n>5000&&flagA){
		cout<<svA();
	}
	else if(m>1e9&&n>5000&&flagB){
		cout<<svB();
	}
	else{
		cout<<sv_nm();
	}
	//fclose()
	fclose(stdin);
	fclose(stdout);
	return 0;
	//What do you want more than a happy ending?
}
	









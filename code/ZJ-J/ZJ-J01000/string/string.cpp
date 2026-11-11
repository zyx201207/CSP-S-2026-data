#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long cnt;
int a[200001]={0};
char c[200001];
char s[100000001];
long long sum1[200001]={0};
long long sum2[200001]={0};
void slove(){
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			tot++;
			s[tot]=c[i];
		}
	}
	if(tot%2==0){
		if(s[tot/2]!=s[tot/2+1]){
			ans++;
		}
		for(int i=1;i<=tot/2;i++){
			int j=tot-i+1;
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}else{
		for(int i=1;i<tot/2+1;i++){
			int j=tot-i+1;
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}
}
char str(int num){//idx -> char
	long long temp=0;
	if(num<a[1]){
		return c[1];
	}
	if(num>a[n]){
		return c[n];
	}
	if(num>a[n-1]){
		return a[n-1];
	}
	for(int i=1;i<=n;i++){
		temp+=a[i];
		if(temp>num){
			return c[i];
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		if(a[i]>500){
			flag=false;
		}
		cnt+=a[i];
		sum1[i]=sum1[i-1]+a[i];
	}
	//if(flag){
		slove();
		cout<<ans;
		return 0;
	//}
	/*if(cnt%2==0){
		if(str(cnt/2)==str(cnt/2+1)){
			ans++;
		}
		long long l=1;
		for(int i=1;i<=n;i++){
			long long r=cnt-l+1;
			if(r<l){
				break;
			}
			if(str(l)==str(r)){
				l+=min(sum1[i]-l,cnt-sum1[n-i+1]);
			}else{
				l+=min(sum1[i]-l,cnt-sum1[n-i+1]);
				ans+=min(sum1[i]-l,cnt-sum1[n-i+1]);
			}
			cout<<l<<endl;
		}
	}else{
		long long l=1;
		for(int i=1;i<=n;i++){
			long long r=cnt-l+1;
			if(r<l){
				break;
			}
			if(str(l)==str(r)){
				l+=min(sum1[i]-l,r-sum1[n-i+1]);
			}else{
				l+=min(sum1[i]-l,r-sum1[n-i+1]);
				ans+=min(sum1[i]-l,r-sum1[n-i+1]);
			}
		}
	}
	cout<<ans;*/
	fclose(stdin);
	fclose(stdout);
}
/*
6
1000000 a
1000000 a
1000000 a
1000000 b
1000000 b
1000000 b
*/

#include<bits/stdc++.h>
using namespace std;
struct sss{
	long long num;
	char c;
}a[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//-------------------------------------
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	int i=1,j=n;
	while(i<j){
		char c1=a[i].c,c2=a[j].c;
		long long a1=a[i].num,a2=a[j].num;
		if(c1==c2){
			if(a1==a2){
				i++;j--;}
			if(a1<a2){
				a[j].num-=a[i].num;
				i++;}
			if(a1>a2){
				a[i].num-=a[j].num;
				j--;}}
		else{
			ans+=min(a1,a2);
			if(a1==a2){
				i++;j--;}
			if(a1<a2){
				a[j].num-=a[i].num;
				i++;}
			if(a1>a2){
				a[i].num-=a[j].num;
				j--;}}}
	cout<<ans;
	//-------------------------------------
	fclose(stdout);fclose(stdin);
	return 0;}
#include<bits/stdc++.h>
using namespace std;
int n,a[200001],l,r;
long long l1,sl,sr,ans;
char c[200001][3],b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],c[i]);
		b[i]=c[i][0];}
	if(n==1){
		cout<<0;
		return 0;}
	l=1;r=n;sl=a[1];sr=a[n];
	while(l<r){
		if(b[l]!=b[r])
			ans+=min(sl-l1,sr-l1);
		l1=min(sl,sr);
		if(sl>sr){
			r--;
			sr+=a[r];
		}else{
			l++;
			sl+=a[l];}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

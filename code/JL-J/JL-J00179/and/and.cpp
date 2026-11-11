#include<bits/stdc++.h>
using namespace std;
bool z[35][200005],zz[200005];
long long t[35][35],a[200005],p2[35],n,c=1;
void ao(int i,long long b){
	int bb=1;
	if(b==0){
		z[i][b]=0;
		return;
	}
	while(b) z[bb][i]=b%2,b/=2,t[bb][1]+=z[bb][i],bb++;
	return;
}
void ao1(int i){
	for(int j=1;j<=n;j++)
		if(z[i][j]&&zz[j])
			for(int k=1;k<i;k++)
				t[k][c]+=z[k][j];
		else zz[j]=0;
	return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=200003;i++) zz[i]=1;
    p2[1]=1;
    for(int i=2;i<=30;i++) p2[i]=p2[i-1]*2;
	long long m,tt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ao(i,a[i]);
	}
	for(int i=33;i>=1;i--)
		if(t[i][c]>=m)  tt+=p2[i],c++,ao1(i);
	cout<<tt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

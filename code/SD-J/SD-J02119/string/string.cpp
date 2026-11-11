#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long n,x[200005],len,x1[200005],l=1,r=1,ans,pos3,pos4,len3,len4,cnt=1; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
		x1[i]=x[i];
		len+=x[i];
	}
	len/=2;
	long long pos1=0,sum=0;
	for(int i=1;i<=n;i++){
		sum+=x[i];
		pos1=i;
		if(sum>=len)	break;
	}
	sum-=len;
	x[pos1]-=sum;
	sum=0;
	long long pos2=0;
	for(int i=n;i>=1;i--){
		sum+=x1[i];
		pos2=i;
		if(sum>=len)	break;
	}
	sum-=len;
	x1[pos2]-=sum;
	pos3=1,pos4=n;
	
	while(1){
		if(cnt>len||pos3>pos1||pos4<pos2)	break;
		len3=x[pos3];
		len4=x1[pos4];
		if(a[pos3]!=a[pos4]){
			ans++;
		}
		l++,r++,cnt++;
		if(l>len3){
			pos3++;
			l=1;
		}
		if(r>len4){
			pos4--;
			r=1;
		}
	}
	cout<<ans;
	return 0;
}

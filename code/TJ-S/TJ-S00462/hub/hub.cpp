#include<bits/stdc++.h>
using namespace std;
int n,m,mm,minn=1000000000,ans=-100,cnt,maxnn=-100,wy;
int fs[500010],zs[500010];
int a[500005],b[500005];
void hf(){
	for(int i=1;i<=n;i++)a[i]=b[i];
	sort(a+1,a+1+n);
	m=mm;
}
int hc(){
	for(int i=1;i<=n;i++){
		if(a[i]>=0){
			zs[a[i]]++;
			maxnn=max(maxnn,zs[a[i]]);
		}else{
			fs[0-a[i]]++;
			maxnn=max(maxnn,fs[0-a[i]]);
		}
	}
	return maxnn;
}
int jisuan(){
	sort(a+1,a+1+n);
	if(m==0){
		wy=5;
		return hc();
	}
	for(int i=2;i<=n;i++){
		int tmp=a[i]-a[i-1];
		if(tmp<=m&&tmp!=0){
			a[i-1]+=tmp;
			m-=tmp;
			ans=max(ans,jisuan());
	
		}
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	mm=m;
	for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int tmp=a[i]-a[i-1];
		if(tmp>m) cnt++;	
	}
	if(cnt==n-1){cout<<1;return 0;}
	cout<<jisuan();
	return 0;
}

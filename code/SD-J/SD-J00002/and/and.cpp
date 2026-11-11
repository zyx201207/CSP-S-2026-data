#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],p=1,mm,p1=1,ans;
bool cc[40],dd[40];
int qed(int a,int b){
	ans=0;
	int i;
	for(i=1;i<=a;i*=2);
	i/=2;
	int j=i;
	for(;i>=1;i/=2){
		if(a>=i){
			a-=i;
			cc[p1]=1;
		}
		if(b>=i){
			b-=i;
			dd[p1]=1;
		}
		p1++;
	}
	for(i=1;i<=p1;j/=2,i++){
		if(cc[i]&&dd[i]){
			ans+=j;
		}
	}
	p1=1;
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1){
		for(int i=1;i<=n;i++){
			if(mm<a[i])mm=a[i];
		}
		printf("%d",mm);
		return 0;
	}
	if(m==2){for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[p]=qed(a[i],a[j]);
			p++;
		}
	}//不会DP,BFS,DFS,vecote(是这么拼吗),queue,map,tree 
	for(int i=1;i<=p;i++){
		if(b[i]>mm)mm=b[i];
	}
	printf("%d",mm);
	return 0;
	}
	if(m==n){
		mm=a[1];
		for(int i=1;i<=n;i++){
			mm=qed(mm,a[i]);
		}
		printf("%d",mm);
		return 0;
	}//暴力抢一点分
	return 0; 
}

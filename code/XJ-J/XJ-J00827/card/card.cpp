#include<bits/stdc++.h>
using namespace std;
const long long P=5e5+5;
long long num[P];
struct card{
	long long time,ty;
}sum[P];
bool cmp(card x,card y){
	return x.ty<y.ty;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]!=sum[t].ty ){
			t++;
			sum[t].ty =num[i];
			sum[t].time =1;
		}
		else {
			sum[t].time++;
		}
	}
	sort(sum+1,sum+m+1,cmp);
	for(int i=1;i<=m;i++)sum[i].time+=sum[i-1].time;
	for(int i=1;i<=m;i++){
		cout<<sum[i].time<<" ";
	}
	return 0;
}

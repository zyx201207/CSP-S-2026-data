#include<iostream>
using namespace std;
int n;
long long a[200005],L,mid1,mid2,pos1,pos2,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i]; 
	}
	if(L%2==0) mid1=L/2,mid2=L/2+1;
	else mid1=L/2+1,mid2=L/2+1;
	pos1=0,pos2=L+1;
	int id1=0,id2=n+1,cnt1=0,cnt2=0;
	while(pos1<mid1||pos2>mid2){
		if(cnt1==0){
			id1++;
			if(a[id1]>(mid1-pos1)) cnt1=mid1-pos1,pos1=mid1;
			else cnt1=a[id1],pos1+=a[id1];
		}
		else if(cnt2==0){
			id2--;
			if(a[id2]>(pos2-mid2)) cnt2=pos2-mid2,pos2=mid2;
			else cnt2=a[id2],pos2-=a[id2];
		}
		if(c[id2]==c[id1]){
			if(cnt1>cnt2) cnt1-=cnt2,cnt2=0;
			else if(cnt2>cnt1) cnt2=cnt2-cnt1,cnt1=0;
			else cnt1=0,cnt2=0;
		}
		else if(c[id2]!=c[id1]){
			if(cnt1>cnt2) ans+=cnt2,cnt1-=cnt2,cnt2=0;
			else if(cnt2>cnt1) ans+=cnt1,cnt2-=cnt1,cnt1=0;
			else ans+=cnt1,cnt1=0,cnt2=0;
		}
	}
	cout<<ans;
	return 0;
} 

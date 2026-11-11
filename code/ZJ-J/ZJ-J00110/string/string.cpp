#include <iostream>
using namespace std;
#define ll long long
//head

struct node{
	char c;
	ll lenth;
};
//class

ll n,len,tl,tr,ans;
node a[200010],l[200010],r[200010];
//val

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].lenth>>a[i].c;
		len+=a[i].lenth;
	}
	ll sum=0,i,j;
	for(i=1;i<=n;i++){
		sum+=a[i].lenth;
		if(sum>len/2) break;
		l[++tl]=a[i];
	}
	//cout<<i<<' ';
	if(len&1){
		if(len/2+a[i].lenth!=sum) l[++tl]=(node){a[i].c,len/2-sum+a[i].lenth};
		if(sum-1!=len/2) r[++tr]=(node){a[i].c,sum-len/2-1};
	}else{
		if(len/2+a[i].lenth!=sum) l[++tl]=(node){a[i].c,len/2-sum+a[i].lenth};
		if(sum!=len/2) r[++tr]=(node){a[i].c,sum-len/2};
	}
	i++;
	//cout<<i<<' ';
	for(;i<=n;i++){
		r[++tr]=a[i];
		//cout<<r[i].lenth<<' ';
	}
	/*
	for(i=1;i<=tl;i++){
		cout<<l[i].c<<' '<<l[i].lenth<<'\n';
	}
	cout<<'\n';
	for(i=1;i<=tr;i++){
		cout<<r[i].c<<' '<<r[i].lenth<<'\n';
	}
	*/
	i=1,j=tr;
	while(i<=tl&&j>=1){
		//cout<<l[i].lenth<<' '<<r[j].lenth<<' ';
		if(l[i].lenth>r[j].lenth){
			if(l[i].c!=r[j].c) ans+=r[j].lenth;
			l[i].lenth-=r[j].lenth;
			j--;
		}else if(l[i].lenth<r[j].lenth){
			if(l[i].c!=r[j].c) ans+=l[i].lenth;
			r[j].lenth-=l[i].lenth;
			i++;
		}else{
			if(l[i].c!=r[j].c) ans+=l[i].lenth;
			//cout<<ans<<' ';
			i++,j--;
		}
		//cout<<'\n';
	}
	cout<<ans;
	
	return 0;
}

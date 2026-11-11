#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt=0,l=1,r,sl=0,sr=0;
long long ans=0;
struct arr{
	long long _1shu_liang;
	char _2_name;
};
arr a[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]._1shu_liang>>a[i]._2_name;
	}
	r=n;
	l=1;
	while(l<r){
		sl=a[l]._1shu_liang;
		long long i=r;
		sr=0;
		for(r;r>l;){
			if(sr+a[r]._1shu_liang<sl){
				if(a[r]._2_name!=a[l]._2_name){
					ans+=a[r]._1shu_liang;
				}
				sr+=a[r]._1shu_liang;
				r--;
			}else{
				if(a[r]._2_name!=a[l]._2_name){
					ans+=(sl-sr);
				}
				a[r]._1shu_liang=a[r]._1shu_liang-sl+sr;//sr+a>=sl
				break;
			}
		}
		l++;
	}
	cout<<ans<<endl;
	return 0;
}

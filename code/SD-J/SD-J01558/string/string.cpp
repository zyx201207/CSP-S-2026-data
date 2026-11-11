#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2e5+5;
//int a[maxn],s3,s[maxn],s2[maxn];
//char c[maxn];
int ans;
struct f{
	int id;
	int l,r;
	int ss;
	char name;
};
f a[maxn],b[maxn];
int maxx=0;
int s3=0;
int cnt=0;
bool cmp(f a,f b){
	if(a.ss!=b.ss){
		return a.ss>b.ss;
	}
	return a.l<b.l;
}
void lr(){
	if(b[1].name!=b[cnt].name){
		if(b[1].ss!=b[cnt].ss){
			for(int i=1;i<=cnt&&b[1].ss<b[cnt].ss;i++){
				if(b[i].name==a[1].name){
//					a[1].l=b[i].l;
					for(int j=a[1].l;j>i;j--){
						a[1].r=b[j].r;
						ans+=b[j].ss;
					}
					break;
				}
				b[1].ss+=b[i].ss;
				b[1].r=b[i].r;
				ans+=b[i].ss;
			}
			for(int j=cnt;j>a[1].r;j--){
				if(b[j].name==a[1].name){
					for(int k=a[1].r+1;k<=j;k++){
						a[1].r=b[k].r;
						ans+=b[k].ss;
					}
					break;
				}
			}
			ans+=b[1].ss;
			return;
		}else{
			for(int i=b[1].l+1;i<b[cnt].l;i++){
				if(b[i].name!=a[1].name){
					ans+=b[i].ss;
				}
			}
		}
	}else{
		for(int i=1;i<=cnt&&b[1].ss<b[cnt].ss;i++){
			if(b[i].name==a[1].name){
//					a[1].l=b[i].l;
				for(int j=a[1].l;j>i;j--){
					a[1].r=b[j].r;
					ans+=b[j].ss;
				}
				break;
			}
			b[1].ss+=b[i].ss;
			b[1].r=b[i].r;
			ans+=b[i].ss;
		}
		for(int j=cnt;j>a[1].r;j--){
			if(b[j].name==a[1].name){
				for(int k=a[1].r+1;k<=j;k++){
					a[1].r=b[k].r;
					ans+=b[k].ss;
				}
				break;
			}
		}
		ans+=b[1].ss-b[cnt].ss;
		return;
	}
}
signed main(){
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int s;
		char c;
		cin>>s>>c;
		if(cnt!=0){
			if(a[cnt].name==c){
				a[cnt].ss+=s;
				b[cnt].ss+=s;
				s3+=s;
				b[cnt].l=s3+1;
				a[cnt].r=s3;
				b[cnt].r=s3;
			}else{
				cnt++;
				a[cnt].name=c;
				a[cnt].ss=s;
				a[cnt].l=s3+1;
				b[cnt].name=c;
				b[cnt].ss=s;
				b[cnt].l=s3+1;
				s3+=s;
				a[cnt].r=s3;
				b[cnt].r=s3;
			}
		}else{
			cnt++;
			a[cnt].name=c;
			a[cnt].ss=s;
			a[cnt].l=s3+1;
			b[cnt].name=c;
			b[cnt].ss=s;
			b[cnt].l=s3+1;
			s3+=s;
			a[cnt].r=s3;
			b[cnt].r=s3;
		}
		if(a[cnt].ss>maxx){
			maxx=a[cnt].ss;
			a[cnt].id=cnt;
			b[cnt].id=cnt;
		}
//		for(int j=1;j<=n;j++){
//			if(a[j].name>='a'&&a[j].name<='z'){
//				if(a[j].name==c){
//					
//					break;
//				}
//			}else{
//				
//				break;
//			}
//		}
	}
	sort(a+1,a+1+cnt,cmp);
	if(s3%2==0){
		//cout<<1<<endl;
		if((a[1].l<=s3/2)&&(a[1].r>=s3/2+1)){
//			cout<<3<<endl;
			lr();
			cout<<ans<<endl;
		}else{
//			cout<<4<<endl;
			for(int i=1;i<=cnt;i++){
//				cout<<5<<endl;
				if(b[i].name!=a[1].name){
					ans+=b[i].ss;
				}
			}
			cout<<ans<<endl;
		}
	}else{
		//cout<<2<<endl;
		//floor
		if((a[1].l<=floor(s3/2))&&(a[1].r>=floor(s3/2))){
			lr();
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=cnt;i++){
				if(b[i].name!=a[1].name){
					ans+=b[i].ss;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 

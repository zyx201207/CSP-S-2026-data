#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e5+10,mod=998244353;
struct node{
	ll len;
	char ch;
}a[N],b[N],c[N],d[N];
ll n,cnt1,cnt,num,stlen,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cnt=num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].ch;
		cnt1+=a[i].len;
	}
	ll mid=cnt1/2;
	for(int i=1;i<=n;i++){
		if(stlen+a[i].len<=mid){
			num++;
			b[num].len=a[i].len;
			b[num].ch=a[i].ch;
			stlen+=a[i].len;
//			cout<<"B "<<a[i].len<<" "<<a[i].ch<<endl;
		}else if(stlen<=mid&&stlen+a[i].len>mid){
			if(cnt1%2){
				if(stlen!=mid){
					num++;
					b[num].ch=a[i].ch;
					b[num].len=mid-stlen;
					if(a[i].len>2){
						cnt++;
						c[cnt].len=a[i].len-b[num].len-1;
						c[cnt].ch=a[i].ch;
					}
//					cout<<"╩Л "<<a[i].ch<<" "<<a[i].len<<endl; 
				}else{
					if(a[i].len>1){
						cnt++;
						c[cnt].ch=a[i].ch;
						c[cnt].len=a[i].len-1;
//						cout<<"ср "<<a[i].ch<<" "<<a[i].len<<endl;
					}
				}
				stlen+=a[i].len;
			}else{
				if(stlen!=mid){
					num++;
					b[num].ch=a[i].ch;
					b[num].len=mid-stlen;
					cnt++;
					c[cnt].len=a[i].len-b[num].len;
					c[cnt].ch=a[i].ch;
				}else{
					cnt++;
					c[cnt].ch=a[i].ch;
					c[cnt].len=a[i].len;
				}
				stlen+=a[i].len;
			}
		}else{
//			cout<<"C "<<a[i].len<<" "<<a[i].ch<<endl;
			cnt++;
			c[cnt].len=a[i].len;
			c[cnt].ch=a[i].ch;
		}
	}
//	cout<<"B\n";
//	for(int i=1;i<=num;i++){
//		cout<<b[i].ch<<" "<<b[i].len<<endl;
//	}
//	cout<<"C\n";
//	for(int i=1;i<=cnt;i++){
//		cout<<c[i].ch<<" "<<c[i].len<<endl;
//	}
//	ll l=1,r=cnt;
//	for(;l<=num;l++){
//		while(r>0&&b[l].len>=c[r].len&&b[l].ch==c[r].ch){
//			b[l].len-=c[r].len;
//			r--;
//		}
//		if(b[l].len==0) continue;
//		if(r==0) break;
//		else{
//			while(r>0&&b[l].len>=c[r].len&&b[l].ch!=c[r].ch)
//		}
//	}
	ll l=1;
	for(int i=1;i<=cnt;i++){
		d[cnt-i+1].ch=c[i].ch;
		d[cnt-i+1].len=c[i].len;
	}
	for(int i=1;i<=num;i++){
		while(l<cnt&&b[i].len>=d[l].len){
			if(b[i].ch!=d[l].ch) ans+=d[l].len;
			b[i].len-=d[l].len;
			l++;
		}
		if(b[i].len==0) continue;
		d[l].len-=b[i].len;
		if(d[l].ch!=b[i].ch) ans+=b[i].len;
	}
	cout<<ans<<endl;
	return 0;
}


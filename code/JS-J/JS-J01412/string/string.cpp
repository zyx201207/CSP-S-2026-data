#include<bits/stdc++.h>
using namespace std;
long long n,z,cnt,ans,nxt,wz;
bool fx=1;
bool vis[1000000];
char lst;
struct node{
	long long gs;
	char c;
}a[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].gs>>a[i].c;
	}
	wz=n;
	nxt=1;
	cnt=a[wz].gs;
	lst=a[wz].c;
	for(int i=1;i<=n;i++){
		//cout<<i<<':'<<nxt<<' '<<wz<<' '<<a[nxt].c<<' '<<lst<<endl;
		if(nxt==wz||vis[nxt]==1&&vis[wz]==1){
			break;
		}
		if(lst==a[nxt].c){
			if(cnt>a[nxt].gs){
				cnt-=a[nxt].gs;
				vis[nxt]=1;
				if(fx==1){
					nxt++;
				}else{
					nxt--;
				}
			}else if(cnt<a[nxt].gs){
				vis[wz]=1;
				a[nxt].gs-=cnt;
				fx=!fx;
				swap(lst,a[nxt].c);
				swap(cnt,a[nxt].gs);
				swap(wz,nxt);
				if(fx==1){
					nxt++;
				}else{
					nxt--;
				}
			}else{
				vis[wz]=1;
				vis[nxt]=1;
				if(fx==1){
					nxt++;
					wz--;
				}else{
					nxt--;
					wz++;
				}
			}
		}else{
			if(cnt>a[nxt].gs){
				ans+=a[nxt].gs;
				vis[nxt]=1;
				cnt-=a[nxt].gs;
				if(fx==1){
					nxt++;
				}else{
					nxt--;
				}
			}else if(cnt<a[nxt].gs){
				ans+=cnt;
				vis[wz]=1;
				a[nxt].gs-=cnt;
				fx=!fx;
				swap(lst,a[nxt].c);
				swap(cnt,a[nxt].gs);
				swap(wz,nxt);
				if(fx==1){
					nxt++;
				}else{
					nxt--;
				}
			}else{
				ans+=a[nxt].gs;
				vis[wz]=1;
				vis[nxt]=1;
				if(fx==1){
					nxt++;
					wz--;
				}else{
					nxt--;
					wz++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,ans,sum;
int aa[200005],a[200005];
char cc[200005],c[200005];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> aa[i] >> cc[i];
		sum+=aa[i]; 
	}
	
	int cnt = 1;
	for(int i = 1,num = 0;i<=n;i++){
		if(num<(sum+1)/2 && (sum+1)/2<num+aa[i]){
			a[cnt++]=(sum+1)/2-num;
			c[cnt-1]=cc[i];
			if(sum%2==1){
				a[cnt-1]--;
				if(a[cnt-1]==0)cnt--;
			}
			a[cnt++]=aa[i]-((sum+1)/2-num);
			c[cnt-1]=cc[i];
		}
		else{
			a[cnt++]=aa[i];
			c[cnt-1]=cc[i];
			if(sum%2==1 && num+aa[i]==(sum+1)/2){
				a[cnt-1]--;
				if(a[cnt-1]==0)cnt--;
			}
		}
		//clog << cnt-1 << " " << num << " " << i << endl;
		num+=aa[i]; 
	}
	n = cnt - 1;
//	cout << "begin------" << endl;
//	for(int i = 1;i<=n;i++){
//		cout << "999999" << endl; 
//		cout << a[i] << " " << c[i] << endl;
//		cout << "888888" << endl; 
//	}
//	cout << "end--------" << endl;
	int l = 1,r = n;
	int ln = 0,rn = 0;
	int t = 0;
	char ch = 0;
	while(l<=r){
		if(ln<=rn){//×ó 
			if(ch && c[l]!=ch){
				ans+=min(a[l],t);
			}
			if(a[l]>=t){
				if(a[l]==t)ch=0;
				else ch=c[l];
				t = a[l]-t;
			}
			else{
				t = t - a[l];
			}
			ln+=a[l],l++;
		}
		else{//ÓÒ 
			if(ch && c[r]!=ch){
				ans+=min(a[r],t);
			}
			if(a[r]>=t){
				if(a[r]==t)ch=0;
				else ch=c[r];
				t = a[r]-t;
			}
			else{
				t = t - a[r];
			}
			rn+=a[r],r--;
		}
//		clog << l << " " << r << " " << ans << " " << (ch?ch:(char)0) << endl;
//		clog << ln << " " << rn << " " << t << endl;
//		clog << endl;
	}
	cout << ans;
	return 0;
}


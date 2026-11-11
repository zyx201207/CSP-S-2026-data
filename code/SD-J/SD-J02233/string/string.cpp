#include<iostream>
using namespace std;
#define ll long long
const int N=2e5+10;
struct fun_yebex{
	int num;
	char c;
}a[N];
int n,maxx;
ll t_l[30],t_r[30],len,ans;
char s[100000005];
void fun_locax(){
	for(int i=0;i<26;i++){
		ll kn=abs(t_l[i]-t_r[i]);
		ans+=kn;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		len+=a[i].num;
		maxx=max(maxx,a[i].num);
	}
	if(maxx<=500){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].num;j++){
				s[++cnt]=a[i].c;
			}
		}
		if(cnt%2==0){
			for(int l=1,r=cnt;l<r;l++,r--){
				if(s[l]!=s[r])ans++;
			}
		}else{
			for(int l=1,r=cnt;l<r;l++,r--){
				if(s[l]!=s[r]){
					ans++;				
				}
			}
		}
		cout<<ans<<"\n";
		return 0;
	}else{
		if(len%2==0){
			ll len_l=len/2,cnt=0,pos=0;
			for(int i=1;i<=n;i++){
				pos=i;
				if(cnt+a[i].num>len_l){
					t_l[a[i].c-'a']+=len_l-cnt;
					t_r[a[i].c-'a']+=cnt+a[i].num-len_l;
					break;
				}
				cnt+=a[i].num;
				t_l[a[i].c-'a']+=a[i].num;
			}
			for(int i=pos+1;i<=n;i++){
				t_r[a[i].c-'a']+=a[i].num;
			}
			fun_locax();
		}
		else{
			ll len_l=len/2,cnt=0,pos=0;
			for(int i=1;i<=n;i++){
				pos=i;
				if(cnt+a[i].num==len_l){
					t_l[a[i].c-'a']+=a[i].num;
					a[i+1].num--;
					break;
				}else if(cnt+a[i].num==len_l+1){
					t_l[a[i].c-'a']+=a[i].num-1;
					break;
				}else if(cnt+a[i].num>len_l+1){
					t_l[a[i].c-'a']+=len_l-cnt;
					t_r[a[i].c-'a']+=cnt+a[i].num-len_l-1;
					break;
				}
				cnt+=a[i].num;
				t_l[a[i].c-'a']+=a[i].num;
			}
			for(int i=pos+1;i<=n;i++){
				t_r[a[i].c-'a']+=a[i].num;
			}
			fun_locax();
		}
	}
	cout<<ans;
	return 0;
}

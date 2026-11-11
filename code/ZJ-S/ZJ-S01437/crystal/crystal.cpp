#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
//rp++;
const int maxn=1<<19;
int n,m,a[maxn],ans=1;
void abandoned_idea() {
	//	×ö»¬¶¯´°¿Ú£¬´°¿ÚÖÐ¾àÀëÖ®ºÍ×î¶Ì´¦Î»ÓÚÖÐÖµµã
	int l=1,r=1,cnt=0;
	while(r<=n) {
		/*
		µ±[l,r]¸öÊýÎªÆæÊýÊ±£¬l+rÎªÅ¼Êý£¬Ö´ÐÐl++ºÍr++£¬mid²»±ä£¬ÎÞÐèÖ¤Ã÷
		µ±[l,r]¸öÊýÎªÅ¼ÊýÊ±£¬l+rÎªÆæÊý£¬midÓëmid+1¶¼ÊÇÖÐÖµµã
		Ö´ÐÐr++£¬ÐÂr¼ÇÎªr'£¬l+r'ÎªÅ¼Êý£¬mid±äÎªmid+1£¬¶ÔÓÚ[l,r]Çø¼ä£¬¾àÀëºÍ²»±ä
		¹Êcnt+=a[r']-a[mid']
		Í¬Àí£¬l++Ê±£¬cnt-=a[mid']-a[l]¼´cnt+=a[l]-a[mid']
		*/
		ans=max(ans,r-l+1);
		cnt+=a[++r]-a[l+r>>1];
		while(cnt>m)cnt+=a[l++]-a[l+r>>1];
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+1+n);
	//abandoned_idea();//Ð´ÍêÁË²Å¿´µ½Ö»ÄÜ+1²»ÄÜ-1£¬¹þ»ù€€¡êÄãÕâ¼Ò»ï
	//€€¡êµÄ´ò·¨£ºAlt+Ð¡¼üÅÌ0128£¬Alt+Ð¡¼üÅÌ0128£¬Alt+Ð¡¼üÅÌ0163
	int l=1,r=1,cnt=0;
	//Ö»ÄÜ+1£¬ÄÇÃ´¾ÍÖ±½ÓÓë×îÓÒ²à±êÆë
	while(r<=n) {
		ans=max(ans,r-l+1);
		cnt+=(r-l+1)*(a[r+1]-a[r++]);
		while(cnt>m)cnt-=a[r]-a[l++];
	}
	cout<<ans;
	return 0;
}

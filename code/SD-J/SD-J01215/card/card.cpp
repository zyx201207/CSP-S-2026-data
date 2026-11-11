#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],bas[300005],cnt[300005],lst[300005];
bool del[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			memset(bas,0,sizeof(bas));
			memset(del,0,sizeof(del));
			if(!bas[a[j]]){
				bas[a[j]]++;
				lst[a[j]]=j;
			}
			else{
				for(int k=lst[a[j]];k<j;k++){
					bas[a[k]]-=(int)(!del[k]);
					del[k]=1;
				}
				lst[a[j]]=j;
			}
			for(int k=1;k<=m;k++){
				cnt[k]+=bas[k];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[m]<<" ";
	}
	cout<<'\n';
	return 0;
}
/*
My Luogu uid is 1634908
T1:writing--20min-->maybe AC
T2:writing--20min-->brute--40min-->near AC
T3:writing--30min-->brute
T4:writing--???min-->I can't solve this
sto ZAK orz
The keyboard is uncomfortable
RRRRRRR PPPPPPP    +       +
R     R P     P    +       +     ;;
R     R P     P    +       +     ;;
RRRRRRR PPPPPPP +++++++ +++++++
RR      P          +       +     ;;
R R     P          +       +     ;;
R  R    P          +       +     ;
R   R   P          +       +    ;
Please give me Au
Please give me 1=
Please give me 2*AC
HAuCl4+SnCl2+NaOH+C6H12O6+...=A golden glass bottle
3HAuCl4+Au(OH)3=4AuCl3+3H2O
And last but not least...
Have a nice CSP
2026/10/31
*/

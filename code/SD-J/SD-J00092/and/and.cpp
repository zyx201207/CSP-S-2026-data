#include<iostream>
#include<algorithm>
#define ine long long
using namespace std;
int n,m,a[200010],t[1050000];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=2000){
		if(m==1){
			sort(a+1,a+1+n,cmp);
			cout<<a[1];
			return 0;
		}else if(m==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;++i){
				a[1]&=a[i];
			}
			cout<<a[1];
			return 0;
		}else if(m==2){
			int maxx=0;
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
			cout<<maxx;
			return 0;
		}else{
			sort(a+1,a+n+1,cmp);
			bool if4=true;
			for(int i=1;i<=n;++i){
				if(a[i]>=4){
					if4=false;
				}
			}
			int maxx=0;
			for(int i=1;i<=n;++i){
				t[a[i]]++;
				maxx=max(maxx,a[i]);
			}
			int sum=0;
			int ans=a[1];
			for(int i=1;i<=n;++i){
				ans&=a[i];
				m-=t[a[i]];
				if(m<1){
					break;
				}
			}
			cout<<ans;
		}	
	}else{
		sort(a+1,a+n+1,cmp);
		bool if4=true;
		for(int i=1;i<=n;++i){
			if(a[i]>=4){
				if4=false;
			}
		}
		int maxx=0;
		for(int i=1;i<=n;++i){
			t[a[i]]++;
			maxx=max(maxx,a[i]);
		}
		int sum=0;
		int ans=a[1];
		for(int i=1;i<=n;++i){
			ans&=a[i];
			m-=t[a[i]];
			if(m<1){
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
/*


···
叮咚(叮叮咚咚) 总部传来命令
前往蓝星 调查人类习性
惺忪(惺惺松松) 困倦还未清零
披上伪装 开始秘密潜行
这独~来~独~往~的身影
这目~中~无~人~的神情 
这无~法~无~天~的行径
似曾相识 (咦,难道说~)
···
说白了泡面辣条充电线
它们本质上就是
罐头猫条毛线球
猫咪就是喜欢
装模做样 大模大样 
觉得我们多高尚 它们多低档
到头来还不是一模一样
··· 


*/

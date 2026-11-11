#include <bits/stdc++.h>
using namespace std;
struct string1{
	long long num;
	char zi;
}s[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].zi;
	}
	int lt=1,rt=n;
	while(1){
		if(lt==rt){
			break;
		}
		if(s[lt].num<=s[rt].num && s[lt].zi!=s[rt].zi){
		   s[rt].num-=s[lt].num;
		   sum+=s[lt].num;
		   lt++;
		}
		else if(s[lt].num>s[rt].num && s[lt].zi!=s[rt].zi){
		   s[lt].num-=s[rt].num;
		   sum+=s[rt].num;
		   rt--;
		}
		else if(s[lt].num<=s[rt].num && s[lt].zi==s[rt].zi){
		   s[rt].num-=s[lt].num;
		   lt++;
		}
		else if(s[lt].num>s[rt].num && s[lt].zi!=s[rt].zi){
		   s[lt].num-=s[rt].num;
		   rt--;
		}
	}
	cout<<sum;
	return 0;

}

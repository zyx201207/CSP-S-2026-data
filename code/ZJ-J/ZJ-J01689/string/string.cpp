#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
int n,len,l=1,length;
char lst=' ';
struct node{
	int l,len;
	char c;
};
vector<node> v;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char ch;
		cin>>x>>ch;
		length+=x;
		if(ch==lst){
			len+=x;
		}else{
//			cout<<l<<" "<<len<<" "<<lst<<" "<<x<<" "<<ch<<endl;
			v.pb(node{l,len,lst});
			lst=ch;
			l+=len;
			len=x;
		}
	}
//	cout<<l<<" "<<len<<" "<<lst<<endl;
	v.pb(node{l,len,lst});
//	for(auto [l,len,ch]:v){
//		cout<<l<<" "<<len<<" "<<ch<<endl;
//	}
	int llen=0,rlen=0,ans=0,j=(int)v.size()-1;
	if(j==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<(int)v.size();i++){
		llen+=v[i].len;
		char ch=v[i].c;
//		cout<<"?"<<llen<<" "<<rlen<<endl;
		if(llen+rlen>length){
			break;
		}
		while(rlen<llen){
			if(length-v[j].l+1>=llen){
				if(v[i].c!=v[j].c){
//					cout<<"!"<<rlen<<" "<<llen<<" "<<llen-rlen<<endl;
					ans+=llen-rlen;
				}
//				cout<<"rlen:"<<llen<<endl;
				rlen=llen;
				break;
			}
			if(v[i].c!=v[j].c){
				ans+=min(v[j].len,(length-v[j].l+1)-rlen);
//				cout<<":"<<min(v[j].len,(length-v[j].l+1)-rlen)<<endl;
//				cout<<"rlen:"<<length-v[j].l+1<<endl;
			}
			rlen=length-v[j].l+1;
			j--;
//			cout<<i<<" "<<j<<" "<<llen<<" "<<rlen<<endl;
//			cout<<"---"<<endl;
		}
//		cout<<"==="<<endl;
		if(llen+rlen>length){
			break;
		}
	}
	end:;
	cout<<ans<<endl;
	return 0;
}
/*
score 100 pts
time 100 min
difficulty 3
because I'm just sleeping lol
this problem is so **** that I don't want to solve it anymore

oh nonono I hate this **** Dev-C++
why I can only see one line of Chinese???

some samples&hacks:
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c

2
2 a
3 a

4
3 a
2 b
3 c
2 d

4
2 a
2 b
2 c
2 d

4
1 a
2 b
3 c
4 d

3
2 a
3 b
1 a
*/
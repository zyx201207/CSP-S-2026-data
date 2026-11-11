#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],len,ans,t;
char c[200005];
struct node{
	int cnt;
	char s;
};
stack<node> s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		t+=a[i];
	}
	for(int i = 1;i <= n;i++){
		if(len+a[i]<t/2+1){
			len+=a[i];
			s1.push({a[i],c[i]});
			//cout<<a[i]<<" "<<c[i]<<endl;
	    }else if(len<t/2){
	    	s1.push({t/2-len,c[i]});
	    	//cout<<t/2-len<<" "<<c[i]<<endl;
	    	break;
		}
	}
	len=0;
	for(int i = n;i >= 1;i--){
		if(len+a[i]<t/2+1){
			len+=a[i];
			s2.push({a[i],c[i]});
			//cout<<a[i]<<" "<<c[i]<<endl;
		}else if(len<t/2){
			s2.push({t/2-len,c[i]});
			//cout<<t/2-len<<" "<<c[i]<<endl;
			break;
		}
	}
	while(s1.size()){
		node now1=s1.top(),now2=s2.top();
		s1.pop();
		s2.pop();
		//cout<<now1.cnt<<" "<<now2.cnt<<endl;
		if(now1.s==now2.s){
			if(now1.cnt>now2.cnt){
				now1.cnt-=now2.cnt;
				s1.push(now1);
			}else if(now1.cnt<now2.cnt){
				now2.cnt-=now1.cnt;
				s2.push(now2);
			}
		}else{
			if(now1.cnt<now2.cnt){
				ans+=now1.cnt;
				now2.cnt-=now1.cnt;
				s2.push(now2);
			}else if(now1.cnt>now2.cnt){
				ans+=now2.cnt;
				now1.cnt-=now2.cnt;
				s1.push(now1);
			}else{
				ans+=now1.cnt;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3 
2 a
2 b
1 c
*/

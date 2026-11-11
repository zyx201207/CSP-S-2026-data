#include <bits/stdc++.h>
using namespace std;
//long long
//printf
//scanf
long long n,a;
string b;
struct node{
	long long sumlen;
	long long len;
	string s;
};
long long cnt=0;
long long sum=0;
node v[200002];
/*
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
long long l=0,r=0;	
long long l1=1;
long long r1=0;
long long ans=0;
long long rlen=0;
void js(){	
	r1=cnt;
	while(l+rlen!=sum){
		l=v[l1].sumlen+v[l1].len;
	    r=v[r1].sumlen+1;
	    rlen=sum-r+1;
		if(l>rlen){
			if(v[r1].s!=v[l1].s){	
				ans+=min(v[l1].len,v[r1].len);
				v[l1].len-=min(v[l1].len,v[r1].len);
				v[r1].len-=min(v[l1].len,v[r1].len);
			}
			r1--;
		}
		if(l<rlen){
			if(v[r1].s!=v[l1].s){	
				ans+=min(v[l1].len,v[r1].len);
				v[l1].len-=min(v[l1].len,v[r1].len);
				v[r1].len-=min(v[l1].len,v[r1].len);
			}
			l1++;
	    }    	
	    if(rlen==l){
			if(v[r1].s!=v[l1].s){	
				ans+=min(v[l1].len,v[r1].len);
			}
			l1++;
			r1--;
		}	
		//cout<<l<<" "<<rlen<<endl;
	}	
	cout<<ans;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
	    cin>>a>>b;
	    cnt++;
	    v[cnt].sumlen=sum;
	    v[cnt].len=a;
	    v[cnt].s=b;
	    sum+=a;
	}
	js();
	return 0;	
}

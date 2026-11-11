#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int a;
    char c;
}
const int N=2e5+5;
node arr[N];
//vector<nod> 5;

int n;
signed main(){
    cin>>n;
    int len=0;
    cin>>arr[1].a>>arr[1].c;
    len += arr[1].a;
    int p=1;
    s[p].a=arr[p].a.s[p].c=arr[p].c;
    for(int i=1;i<=n;i++){
        cin>>arr[1].a>>arr[1].c;
        len+=arr[1].a;
        if(arr[i].c==arr[i-1].c)s[p].a+=arr[i].a;
        else{
            p++;
            s[p].a=arr[i].a;
            s[p].c=arr[i].c;
        }
        if(p==1){
            cout<<0;
            return 0;
        }
    }
    int x=len/2;
    int l=1;r=p;
    int s1=0,s2=0;
    int cnt=0;
    while(l<r){
		if(s1+s2==len)break;
		if(s[l].c==s[r].c){
			cnt+=abs(s[r].a-a[l].a);
			cnt+=s[r].a-s[l].a;
			s1+=s[l].a,s2+=s[l].a;
			s[r].a-=s[i].a;
			
			}
			else{
				cnt+=s[l].a-s[r].a;
				r--;
				a[l].a-=s[r].a;
				}
			
		}
	}


#include<bits/stdc++.h>
using namespace std;
struct S{
    long long len;
    char c;
}a[200005],b[200005];
long long s[200005];
void solve(int n,long long h){
	long long mid;
	if(h%2ll==0){
        long long lsm=h/2;
		for(int i=1;i<=n;i++){
            if(s[i]>=lsm){
                a[i].len+=1;
                break;
            }
		}
	}
	mid=h/2+1;
		deque<S>l,r;
		int id1=0,id2=0;
		for(int i=1;i<=mid;i++){
			if(s[i]>=mid){
				l.push_back({a[i].len,a[i].c});
				id1=i;
				break;
			}
			l.push_back({a[i].len,a[i].c});
		}
		if(id1==n){
			l.pop_back();
			id1--;
		}
		long long ls=0;
		for(int i=n;i>=1;i--){
			ls+=a[i].len;
			if(ls>=mid){
				if(i==n){
					id2=n;
					r.push_back({a[i].len,a[i].c});
				}else{
					id2=i-1;
				}
				break;
			}
			r.push_back({a[i].len,a[i].c});
		}
        long long lll=0,rrr=0;
        for(int i=0;i<r.size();i++){
            rrr+=r[i].len;
        }
        for(int i=0;i<l.size();i++){
            lll+=l[i].len;
            if(lll>rrr && i==l.size()-2){
                //cout<<"w4eyheye"<<"\n";
                r.push_back({l[int(l.size()-1)].len,l[int(l.size()-1)].c});
                l.pop_back();
                id1--;
                id2++;
                break;
            }
        }
        //<<lll<<" "<<rrr<<"\n\n";
        /*for(int i=0;i<id1;i++){
            cout<<l[i].len<<" ";
		}
		cout<<"\n";
		for(int i=0;i<id2;i++){
            cout<<r[i].len<<" ";
		}
		cout<<"\n\n";*/
		long long fix=0;
		int lid=0,rid=0;
		while(lid<id1 && rid<id2){
            //cout<<lid<<" "<<rid<<"\n";
			if(l[lid].len<=r[rid].len){
			    //cout<<"\n1\n";
				if(l[lid].c!=r[rid].c){
					fix+=l[lid].len;
				}
                r[rid].len-=l[lid].len;
				lid++;
			}else{
			    //cout<<"\n2\n";
				if(l[lid].c!=r[rid].c){
					fix+=r[rid].len;
				}
                l[lid].len-=r[rid].len;
                rid++;
			}
		}
		cout<<fix;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	long long h=0;
	for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
        h+=a[i].len;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i].len;
	}
	if(n==1){
        cout<<0;
        return 0;
	}
	if(n==2){
		if(a[1].c==a[2].c){
			cout<<0;
			return 0;
		}
		cout<<min(a[1].len,a[2].len);
		return 0;
	}
	solve(n,h);
	return 0;
}

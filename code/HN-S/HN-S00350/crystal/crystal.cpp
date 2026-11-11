#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,min_=LLONG_MAX;
int a[500010];
int check(int x){
	int pos=lower_bound(a+1,a+n+1,x)-a;
	int sum=0,mm=m;

	for(int i=pos;i<=n;i++){
		if(a[i]!=x)break;
		sum++;
	}

	for(int i=pos-1;i>0;i--){

		mm-=(x-a[i]);
		sum+=1;
		if(mm<0){
			sum--;

			return sum;
		}
	}
	return sum;
}
//1
int kk[500010],kkk=0;
void bl(){
    int ma=LLONG_MIN;
    for(int i=1;i<=kkk;i++){
	ma=max(ma,check(a[kk[i]]));
	}
    cout<<ma;

    exit(0);
}

void A(){
    for(int i=1;i<=n;i++){
        if(a[i]!=i)return;
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        if((i-1)*i/2<=m){
            ans=i;
        }
        else break;
    }
    cout<<ans;
    exit(0);
}
void B(){
    for(int i=2;i<n;i++){
        if(a[i+1]-a[i]!=a[2]-a[1])return;
    }
    int ans=-1;
    //2
    for(int i=1;i<=n;i++){
        if((i-1)*i/2*(a[2]-a[1])<=m){
            ans=i;
        }
        else break;
    }
    cout<<ans;
    exit(0);

}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]); 
            min_=min(min_,a[i]);
    }
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            kk[++kkk]=i;
        }
    }
    if(kkk==1){
        cout<<n<<endl;
        return 0;
    }

    A();

    B();

    bl();


	return 0;
}

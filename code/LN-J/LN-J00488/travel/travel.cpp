# include<bits/stdc++.h>
using namespace std;
# define int long long
int x1,x2,y2,k;
char z1,z2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> x1  >> k>> z1 >>x2 >> y2 >> z2;
    int c1 = z1-'A'+1;
    int c2 = z2-'A'+1;
    if(c1==6) c1--;
    if(c2==6) c2--;
    if(c1<c2) swap(c1,c2);
    if(x1==x2) cout << 1;
    else cout << 0;
    if(x1==x2&&k==y2) cout << 1;
    else cout << 0;
    if(x1==x2&&k==y2&&(max(c1,c2)<4||min(c1,c2)>3)) cout << 1;
    else cout << 0;
    if(x1==x2&&k==y2&&(c1+c2)%2==1&&(c2+1)==c1&&(!(c1==4&&c2==3))) cout << 1;
    else cout << 0;
    return 0;
}

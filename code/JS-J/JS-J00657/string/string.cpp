#include<bits/stdc++.h>
using namespace std;
#define itn long long
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    itn a[n+1],sa[n+1];
    char b[n+1];
    sa[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        //scanf("%lld%lld",&a[i],&b[i]);
        sa[i]=sa[i-1]+a[i];
        //cout<<sa[i]<<" ";
    }
    int l=1,r=n;
    /*for(int i=1;i<=n;i++){
        if(b[i]==b[n-i+1]){
            a[i]-=min(a[i],a[n-i+1]);
            a[n-i+1]-=min(a[i],a[n-i+1]);
        }
    }*/
    /*int he=0;
    while(r>l){

        if(b[l]==b[r]){
            int uu=min(a[r],a[l]);
            a[r]-=uu;
            a[l]-=uu;

            if(a[r]==0){
                r--;
            }
            if(a[l]==0){
                l++;
            }
        }
        else{
            if(a[l]>a[r]){
                he+=a[r];
                a[l]-=a[r];
                a[r]-=a[r];
                if(a[r]==0){
                    r--;
                }
                if(a[l]==0){
                    l++;
                }
            }
            if(a[l]<=a[r]){
                he+=a[l];
                a[r]-=a[l];
                a[l]-=a[l];
                if(a[r]==0){
                    r--;
                }
                if(a[l]==0){
                    l++;
                }
            }
        }
    }
    cout<<he;
    return 0;
    */

    char uu[sa[n]];
    int uu1=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            uu[uu1++]=b[i];
            //cout<<uu[uu1-1];
        }
    }
    uu1--;
    int cou=0;
    for(int i=1;i<=(uu1)/2;i++){
        if(uu[i]==uu[uu1-i+1])continue;
        else{
            cou++;
        }
        //cout<<cou<<" ";
    }
    cout<<cou;
    int he=0;
    return 0;
    /*for(int i=1;i<=n&&he<sa[n]/2;i++){
        if(b[n-i+1]==b[i]){
            continue;
        }
        a[n-i+1]-=a[i];
        a[i]=0;
        int uu=n-i+1;
        while(a[uu]<0){
            a[uu-1]+=a[uu];
            a[uu]-=a[uu]*2;
            uu--;
        }
    }*/

    /*int mid=sa[n]/2+sa[n]%2,midi;
    //cout<<mid<<"   ";
    for(int i=1;i<=n;i++){
        if(sa[i-1]<mid);{
            if(sa[i]>=mid){
                //cout<<mid<<" "<<sa[i-1]<<" "<<sa[i]<<" "<<i<<endl;
                midi=i;
                break;}
        }

    }
    //cout<<mid<<" "<<midi<<endl;
    cout<<(sa[n]-(min(mid-sa[midi-1],sa[midi]-mid+sa[n]%2)*2-1))/2;*/
}

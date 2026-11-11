// #include<bits/stdc++.h>//bu shi ge men zen me dou shi mo ni ti a. ma liang hai zhe me da
// using namespace std;
// #define int long long
// struct node{//bu zhi dao sha ming jiu node ba (sui ran bu shi tu
//     int l,r;//[l,r]
//     char c;
// };
// signed main(){
//     freopen("string.in","r",stdin);
//     freopen("string.out","w",stdout);
//     int n;
//     cin>>n;
//     // vector<long long>a(n);
//     // vector<char>c(n);
//     // long long sum=0;
//     // for(int i=0;i<n;i++){
//     //     cin>>a[i]>>c[i];
//     //     sum+=a[i];
//     // }
//     // long long mid=sum/2,sum2=0,id;
//     // for(int i=0;i<n;i++){
//     //     sum2+=a[i];
//     //     if(sum2>mid){
//     //         id=i;
//     //         break;
//     //     }
//     // }
//     // // cout<<id; zhe li shi dui de
//     // int ans=0,r=n-1;
//     // for(int i=0;i<n;i++){
//     //     while(a.back()<=a[i]){
//     //         r--;
//     //         if(c[r]!=c[i]){
//     //             ans+=
//     //         }
//     //     }
//     // }
// // qwq huan yi zhong xie fa. shang mian de tai e xing l o^o
//     deque<node>a;
    
//     int l=0;
//     for(int i=0;i<n;i++){
//         int x;
//         char cc;
//         cin>>x>>cc;
//         a.push_back({l,l+x,cc});
//         l+=x;
//     }

//     // for(auto x:a)cout<<x.l<<' '<<x.r<<' '<<x.c<<'\n';
    
//     int mid=l/2,sum=l;
//     for(int i=0;i<n;i++){
//         if(a[i].l<=mid&&a[i].r>=mid){
//             //chai cheng lian bian o(n);
//             vector<node>t;
//             for(int j=i;j<n;j++){
//                 t[i]=a[i];
//             }
//             for(int j=i;j<n;j++)a.pop_back();
//             node x=a.back();
//             a.pop_back();
//             a.push_back({x.l,mid,x.c});
//             a.push_back({mid,x.r,x.c});
//             for(int j=i;j<n;j++){
//                 a.push_back(t[j-i]);
//             }
//             //zhe wan yi za yao xie zhe me duo aaaaaaaaaaaa
//             break;
//         }
//     }

//     for(auto x:a)cout<<x.l<<' '<<x.r<<' '<<x.c<<'\n';cout<<'\n';
    
//     int ans=0;
//     while(!a.empty()){
//         if(a.front().r>=sum-a.back().l){
//             int x=sum-a.back().l,y=a.front().r;
//             char c=a.front().c;
//             ans+=(a.front().c!=a.back().c)*(a.front().r-a.front().l);
//             a.pop_back();
//             a.pop_front();
//             a.push_front({x,y,c});
//         }
//         else{
//             int x=a.back().l,y=sum-a.front().r;
//             char c=a.back().c;
//             ans+=(a.front().c!=a.back().c)*(a.back().r-a.back().l);
//             a.pop_back();
//             a.pop_front();
//             a.push_back({x,y,c});
//         }
//         for(auto x:a)cout<<x.l<<' '<<x.r<<' '<<x.c<<'\n';cout<<"\n"<<ans<<"\n\n";
//     }
//     cout<<ans;
//     return 0;
// }
// //aaaaaa wei shen me wo nao zi li yi zhi zai bo fang «shi↑bass↓» aaaaaa
// //                                                     ↑ zhe ge zhen de heng hao ting ("shi" means "try",dont change "bass") 
#include<bits/stdc++.h>
using namespace std;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=0;i<n;i++){
        int x;
        string t;
        cin>>x>>t;
        while(x--)s=s+t;
    }
    int sz=s.size(),ans=0;
    for(int i=0;i<sz/2;i++){
        if(s[i]!=s[sz-i-1])ans++;
    }
    cout<<ans;
    return 0;
}


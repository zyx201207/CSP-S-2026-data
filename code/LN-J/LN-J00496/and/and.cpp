#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005];
long long s,t;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=2;j<=n;j++){
                if(i!=j){
                    t=a[i]&a[j];
                    s=max(s,t);
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==n){
        for(int i=1;i<=n;i++) s&=a[i];
        cout<<s;
        return 0;
    }
    else if(m==n-1){
        sort(a+1,a+1+n);
        for(int i=2;i<=n;i++) s&=a[i];
        cout<<s;
        return 0;
    }
    else if(m==3){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    if(a1!=b&&b!=c&&a1!=c){
                        t=a[a1]&a[b]&a[c];
                        s=max(s,t);
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==4){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d){
                            t=a[a1]&a[b]&a[c]&a[d];
                            s=max(s,t);
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==5){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e){
                                t=a[a1]&a[b]&a[c]&a[d]&a[e];
                                s=max(s,t);
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==6){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f){
                                    t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f];
                                    s=max(s,t);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==7){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g){
                                        t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g];
                                        s=max(s,t);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==8){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                           c!=h&&d!=h&&e!=h&&f!=h&&g!=h){
                                            t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h];
                                            s=max(s,t);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==9){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                            c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i){
                                                t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i];
                                                s=max(s,t);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==10){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j){
                                                    t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j];
                                                    s=max(s,t);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==11){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                    c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                    &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k){
                                                        t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k];
                                                        s=max(s,t);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==12){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    for(int l=12;l<=n;l++){
                                                        if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                        c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                        &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k&&a1!=l&&b!=l&&c!=l&&d!=l&&e!=l&&f!=l&&g!=l&&h!=l&&i!=l&&j!=l){
                                                            t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l];
                                                            s=max(s,t);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==13){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    for(int l=12;l<=n;l++){
                                                        for(int m1=13;m1<=n;m1++){
                                                            if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                            c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                            &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k&&a1!=l&&b!=l&&c!=l&&d!=l&&e!=l&&f!=l&&g!=l&&h!=l&&i!=l&&j!=l&&a1!=m1&&b!=m1
                                                            &&c!=m1&&d!=m1&&e!=m1&&f!=m1&&g!=m1&&h!=m1&&i!=m1&&j!=m1&&k!=m1&&l!=m1){
                                                                t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1];
                                                                s=max(s,t);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==14){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    for(int l=12;l<=n;l++){
                                                        for(int m1=13;m1<=n;m1++){
                                                            for(int n1=14;n1<=n;n1++){
                                                                if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                                c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                                &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k&&a1!=l&&b!=l&&c!=l&&d!=l&&e!=l&&f!=l&&g!=l&&h!=l&&i!=l&&j!=l&&a1!=m1&&b!=m1
                                                                &&c!=m1&&d!=m1&&e!=m1&&f!=m1&&g!=m1&&h!=m1&&i!=m1&&j!=m1&&k!=m1&&l!=m1&&a1!=n1&&b!=n1&&c!=n1&&d!=n1&&e!=n1&&f!=n1&&g!=n1&&h!=n1
                                                                &&i!=n1&&j!=n1&&k!=n1&&l!=n1&&m1!=n1){
                                                                    t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1];
                                                                    s=max(s,t);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==15){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    for(int l=12;l<=n;l++){
                                                        for(int m1=13;m1<=n;m1++){
                                                            for(int n1=14;n1<=n;n1++){
                                                                for(int o=15;o<=n;o++){
                                                                    if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                                    c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                                    &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k&&a1!=l&&b!=l&&c!=l&&d!=l&&e!=l&&f!=l&&g!=l&&h!=l&&i!=l&&j!=l&&a1!=m1&&b!=m1
                                                                    &&c!=m1&&d!=m1&&e!=m1&&f!=m1&&g!=m1&&h!=m1&&i!=m1&&j!=m1&&k!=m1&&l!=m1&&a1!=n1&&b!=n1&&c!=n1&&d!=n1&&e!=n1&&f!=n1&&g!=n1&&h!=n1
                                                                    &&i!=n1&&j!=n1&&k!=n1&&l!=n1&&m1!=n1&&a1!=o&&b!=o&&c!=o&&d!=o&&e!=o&&f!=o&&g!=o&&h!=o&&i!=o&&j!=o&&k!=o&&l!=o&&m1!=o&&n1!=o){
                                                                        t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o];
                                                                        s=max(s,t);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==16){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    for(int l=12;l<=n;l++){
                                                        for(int m1=13;m1<=n;m1++){
                                                            for(int n1=14;n1<=n;n1++){
                                                                for(int o=15;o<=n;o++){
                                                                    for(int p=16;p<=n;p++){
                                                                        if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                                        c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                                        &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k&&a1!=l&&b!=l&&c!=l&&d!=l&&e!=l&&f!=l&&g!=l&&h!=l&&i!=l&&j!=l&&a1!=m1&&b!=m1
                                                                        &&c!=m1&&d!=m1&&e!=m1&&f!=m1&&g!=m1&&h!=m1&&i!=m1&&j!=m1&&k!=m1&&l!=m1&&a1!=n1&&b!=n1&&c!=n1&&d!=n1&&e!=n1&&f!=n1&&g!=n1&&h!=n1
                                                                        &&i!=n1&&j!=n1&&k!=n1&&l!=n1&&m1!=n1&&a1!=o&&b!=o&&c!=o&&d!=o&&e!=o&&f!=o&&g!=o&&h!=o&&i!=o&&j!=o&&k!=o&&l!=o&&m1!=o
                                                                        &&n1!=o&&a1!=p&&b!=p&&c!=p&&d!=p&&e!=p&&f!=p&&g!=p&&h!=p&&i!=p&&j!=p&&k!=p&&l!=p&&m1!=p&&n1!=p&&o!=p){
                                                                            t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p];
                                                                            s=max(s,t);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==17){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    for(int l=12;l<=n;l++){
                                                        for(int m1=13;m1<=n;m1++){
                                                            for(int n1=14;n1<=n;n1++){
                                                                for(int o=15;o<=n;o++){
                                                                    for(int p=16;p<=n;p++){
                                                                        for(int q=17;q<=n;q++){
                                                                            if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                                            c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                                            &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k&&a1!=l&&b!=l&&c!=l&&d!=l&&e!=l&&f!=l&&g!=l&&h!=l&&i!=l&&j!=l&&a1!=m1&&b!=m1
                                                                            &&c!=m1&&d!=m1&&e!=m1&&f!=m1&&g!=m1&&h!=m1&&i!=m1&&j!=m1&&k!=m1&&l!=m1&&a1!=n1&&b!=n1&&c!=n1&&d!=n1&&e!=n1&&f!=n1&&g!=n1&&h!=n1
                                                                            &&i!=n1&&j!=n1&&k!=n1&&l!=n1&&m1!=n1&&a1!=o&&b!=o&&c!=o&&d!=o&&e!=o&&f!=o&&g!=o&&h!=o&&i!=o&&j!=o&&k!=o&&l!=o&&m1!=o
                                                                            &&n1!=o&&a1!=p&&b!=p&&c!=p&&d!=p&&e!=p&&f!=p&&g!=p&&h!=p&&i!=p&&j!=p&&k!=p&&l!=p&&m1!=p&&n1!=p&&o!=p&&a1!=q&&b!=q
                                                                            &&c!=q&&d!=q&&e!=q&&f!=q&&g!=q&&h!=q&&i!=q&&j!=q&&k!=q&&l!=q&&m1!=q&&n1!=q&&o!=q&&p!=q){
                                                                                t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q];
                                                                                s=max(s,t);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==18){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    for(int l=12;l<=n;l++){
                                                        for(int m1=13;m1<=n;m1++){
                                                            for(int n1=14;n1<=n;n1++){
                                                                for(int o=15;o<=n;o++){
                                                                    for(int p=16;p<=n;p++){
                                                                        for(int q=17;q<=n;q++){
                                                                            for(int r=18;r<=n;r++){
                                                                                if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                                                c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                                                &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k&&a1!=l&&b!=l&&c!=l&&d!=l&&e!=l&&f!=l&&g!=l&&h!=l&&i!=l&&j!=l&&a1!=m1&&b!=m1
                                                                                &&c!=m1&&d!=m1&&e!=m1&&f!=m1&&g!=m1&&h!=m1&&i!=m1&&j!=m1&&k!=m1&&l!=m1&&a1!=n1&&b!=n1&&c!=n1&&d!=n1&&e!=n1&&f!=n1&&g!=n1&&h!=n1
                                                                                &&i!=n1&&j!=n1&&k!=n1&&l!=n1&&m1!=n1&&a1!=o&&b!=o&&c!=o&&d!=o&&e!=o&&f!=o&&g!=o&&h!=o&&i!=o&&j!=o&&k!=o&&l!=o&&m1!=o
                                                                                &&n1!=o&&a1!=p&&b!=p&&c!=p&&d!=p&&e!=p&&f!=p&&g!=p&&h!=p&&i!=p&&j!=p&&k!=p&&l!=p&&m1!=p&&n1!=p&&o!=p&&a1!=q&&b!=q
                                                                                &&c!=q&&d!=q&&e!=q&&f!=q&&g!=q&&h!=q&&i!=q&&j!=q&&k!=q&&l!=q&&m1!=q&&n1!=q&&o!=q&&p!=q&&a1!=r&&b!=r&&c!=r&&d!=r&&e!=r
                                                                                &&f!=r&&g!=r&&h!=r&&i!=r&&j!=r&&k!=r&&l!=r&&m1!=r&&n1!=r&&o!=r&&p!=r&&q!=r){
                                                                                    t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]&a[r];
                                                                                    s=max(s,t);
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    else if(m==19){
        for(int a1=1;a1<=n;a1++){
            for(int b=2;b<=n;b++){
                for(int c=3;c<=n;c++){
                    for(int d=4;d<=n;d++){
                        for(int e=5;e<=n;e++){
                            for(int f=6;f<=n;f++){
                                for(int g=7;g<=n;g++){
                                    for(int h=8;h<=n;h++){
                                        for(int i=9;i<=n;i++){
                                            for(int j=10;j<=n;j++){
                                                for(int k=11;k<=n;k++){
                                                    for(int l=12;l<=n;l++){
                                                        for(int m1=13;m1<=n;m1++){
                                                            for(int n1=14;n1<=n;n1++){
                                                                for(int o=15;o<=n;o++){
                                                                    for(int p=16;p<=n;p++){
                                                                        for(int q=17;q<=n;q++){
                                                                            for(int r=18;r<=n;r++){
                                                                                for(int u=19;u<=n;u++){
                                                                                    if(a1!=b&&b!=c&&a1!=c&&a1!=d&&b!=d&&c!=d&&a1!=e&&b!=e&&c!=e&&d!=e&&a1!=f&&b!=f&&c!=f&&d!=f&&e!=f&&a1!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&a1!=h&&b!=h&&
                                                                                    c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&a1!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i&&a1!=j&&b!=j&&c!=j&&d!=j&&e!=j&&f!=j&&g!=j&&h!=j&&i!=j&&a1!=k
                                                                                    &&b!=k&&c!=k&&d!=k&&e!=k&&f!=k&&g!=k&&h!=k&&i!=k&&j!=k&&a1!=l&&b!=l&&c!=l&&d!=l&&e!=l&&f!=l&&g!=l&&h!=l&&i!=l&&j!=l&&a1!=m1&&b!=m1
                                                                                    &&c!=m1&&d!=m1&&e!=m1&&f!=m1&&g!=m1&&h!=m1&&i!=m1&&j!=m1&&k!=m1&&l!=m1&&a1!=n1&&b!=n1&&c!=n1&&d!=n1&&e!=n1&&f!=n1&&g!=n1&&h!=n1
                                                                                    &&i!=n1&&j!=n1&&k!=n1&&l!=n1&&m1!=n1&&a1!=o&&b!=o&&c!=o&&d!=o&&e!=o&&f!=o&&g!=o&&h!=o&&i!=o&&j!=o&&k!=o&&l!=o&&m1!=o
                                                                                    &&n1!=o&&a1!=p&&b!=p&&c!=p&&d!=p&&e!=p&&f!=p&&g!=p&&h!=p&&i!=p&&j!=p&&k!=p&&l!=p&&m1!=p&&n1!=p&&o!=p&&a1!=q&&b!=q
                                                                                    &&c!=q&&d!=q&&e!=q&&f!=q&&g!=q&&h!=q&&i!=q&&j!=q&&k!=q&&l!=q&&m1!=q&&n1!=q&&o!=q&&p!=q&&a1!=r&&b!=r&&c!=r&&d!=r&&e!=r
                                                                                    &&f!=r&&g!=r&&h!=r&&i!=r&&j!=r&&k!=r&&l!=r&&m1!=r&&n1!=r&&o!=r&&p!=r&&q!=r&&a1!=u&&b!=u&&c!=u&&d!=u&&e!=u
                                                                                    &&f!=u&&g!=u&&h!=u&&i!=u&&j!=u&&k!=u&&l!=u&&m1!=u&&n1!=u&&o!=u&&p!=u&&q!=u&&r!=u){
                                                                                        t=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]&a[r]&a[u];
                                                                                        s=max(s,t);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<s;
        return 0;
    }
    sort(a+1,a+1+n);
    cout<<a[n];
    fclose(stdout);
    return 0;
}

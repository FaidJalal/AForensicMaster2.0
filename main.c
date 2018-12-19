#include <stdio.h>
#include <stdlib.h>
#include<string.h>

                                /* ******************SYNC_DRIVE STRUCT VARIABLES************************************** */
struct SDInstall{
    char email[100];
    char location[100];
    char name[100];
}sdInstall;

struct SDLogin{
    char username[50];
    char displayname[50];
    char devicename[50];
    char url[200];
    char time[50];
    char userID[50];
    char deviceID[50];
}sdlogin;

struct SDUpload{
    char filename[50];
    char path[100];
    char url[100];
}sdUpload;

struct SDDload{
    char filename[50];
    char format[50];
    char downloadID[50];
    char path[100];
}sdDload;

struct SDShare{
    char sender[150];
    char receiver[150];
    char filename[50];
    char format[20];
    char type[20];
    char size[20];
    char attachmentID[20];
    char url[150];
    char time[20];
    char date[20];
}sdShare;


                                /* *******************FLIPDRIVE STRUCT VARIABLES************************************** */
struct FDLogin
{
    char firstName[50];
    char lastName[50];
    char email[50];
    char accountHash[200];
    char user[50];
    char userHash[50];
    char accountSize[50];
}fdlogin;

struct FDInstall
{
    char packageName[60];
    char codePath[100];
    char nativeLibrary[100];
    char userID[10];
}fdinstall;

struct FDdelete
{
    char deletedFile[50];
    char deletedFileUserHash[50];
    char deletedFileFirstName[50];
    char deletedFileLastName[50];
}fddelete;

struct FDUpload
{
    char uploadedFile[50];
    char uploadedFileUserHash[50];
    char uploadedFileFirstName[50];
    char uploadedFileLastName[50];
    char uploadedFilePath[100];
}fdupload;


struct FDdownload
{
    char downloadedFile[50];
    char downloadedFileUserHash[50];
    char downloadedFileFirstName[50];
    char downloadedFileLastName[50];
    char downloadedFilePath[100];
}fddownload;


void SyncComForensics();
void SyncInstall();
void SyncLogin();
void SyncUpload();
void SyncDownload();
void SyncShare();
void SyncDelete();

void FlipDriveForensics();
void FlipDriveLogin();
void FlipDriveInstall();
void FlipDriveDelete();
void FlipDriveupload();
void FlipDriveDownload();


int FindIdx(char*,char*);
void strrev(char *str);
int convertToInt(char *val);

int main()
{
    char ch;
    while(1)
    {
        printf("--------------------------------------------------------------------------------\n");
        printf(">>>>>>>      >>>>>>>         ANDROID FORENSIC MASTER        <<<<<<<      <<<<<<<\n");
        printf("--------------------------------------------------------------------------------\n");

        printf("\n\tPress:\n\n\t1 ----- Sync Drive Analysis\n\n\t2 ----- Flip Drive Analysis\n\n\t0 ----- Exit\n\n\tInput Choice:");
        ch=getchar();


        switch(ch)
        {
            case '1':
                SyncComForensics();
                printf("    -----   -----   ---  -----------------------------   ---   -----   -----   \n");
                printf("    <<<<<   <<<<<   <<<  SYNC DRIVE FORENSICS COMPLETE   >>>   >>>>>   >>>>>   \n");
                printf("    -----   -----   ---  -----------------------------   ---   -----   -----   \n\n\n\n\n\n\n");
                break;
            case '2':
                FlipDriveForensics();
                printf("    -----   -----   ---  -----------------------------   ---   -----   -----   \n");
                printf("    <<<<<   <<<<<   <<<  FLIP DRIVE FORENSICS COMPLETE   >>>   >>>>>   >>>>>   \n");
                printf("    -----   -----   ---  -----------------------------   ---   -----   -----   \n\n\n\n\n\n\n");
                break;
            case '0':
                exit(0);
        }
    }
    return 0;
}

void SyncComForensics()
{


    printf("\n\n\n-------------------------------------------------------------------------------\n");
    printf("    --------    --------    --------------------    --------    --------       \n");
    printf("    <<<<<<<<    <<<<<<<<    SYNC DRIVE FORENSICS    >>>>>>>>    >>>>>>>>       \n");
    printf("    --------    --------    --------------------    --------    --------       \n");
    printf("-------------------------------------------------------------------------------\n");


    char* cmd=NULL;
    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /run/media/root/hpDrive/SDdownload.dd | grep -m 1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    if (cmd != NULL)
    {
        //COMMAND FOR DOWNLOAD ANALYSIS
        strcpy(cmd,"hexdump -v -e '\"%010_ad |\" 4096/1 \"%_p\"\"|\\n\"' /run/media/root/hpDrive/SDupload.dd | grep -E -o \"\.[a-zA-Z].*\....\.[0-9]\{16\}\.chunk|.\{0,42\}command=uploadmultichunk.*):|application/[a-z]\{3\}[a-zA-Z0-9]*Download|single_install...*com.sync.mobileapp|username[a-zA-Z].*@.*displayname|LOCAL_FILE\|content://com.sync.mobileapp.*<.*@.*.[a-z]{3}>\\\"\\\".*@.*.[a-z]{3}>.*SERVER_ATTACHMENT|<.*@.*.[a-z]{3}>\\\"\\\".*@.*.[a-z]{3}>.*https://cp.sync.com/.*x.|.\{0,42\}command=[a-z].*):|/storage/emulated/0/.\{0,30\}\">./files/Sync.com/source.txt");
                                                                                                                            //FOR UPLOAD FILE                     //UPLOAD PATH                         //DOWNLOAD FILE                            //INSTALL DETAILS                     //LOGIN DETAILS                 //SHARE DETAILS                                                                                                        //ALL URLS                 //ALL PATH NAMES
    }

    SyncInstall();
    getchar();

    SyncLogin();
    getchar();

    SyncUpload();
    getchar();

    SyncDownload();
    getchar();

    SyncDelete();
    getchar();

    SyncShare();
    getchar();
}


void SyncInstall()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<Installation Analysis of Sync.com>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str1[50],str2[50],temp[50];
    int len;
    int i=0,j=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /run/media/root/TOSHIBA01/Research/SYNC_DRIVE/CS01/SDdownload.dd | grep -m 1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    if (cmd != NULL) {

        //EXTRACT INSTALL EMAIL ID FROM SOURCE.TXT IN FILE INSTALL EMAIL
        strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o \"single_install..[a-zA-Z].*com.sync.mobileap\"> ./files/Sync.com/installEmail.txt");
                                                                 //single_install..[start with an alphabet]*com.sync.mobileapp
        system(cmd);

       //EXTRACT ALL THE PATHNAMES FROM SOURCE.TXT IN FILE INSTALL STORAGE
        strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o \"/storage/.*mobileap\">./files/Sync.com/installStorage.txt");
                                                                // /storage/* mobileap
      //  printf("\n<<<Executing Command on Shell>>>\n %s\n",cmd);
        system(cmd);
    }

    FILE *fp1;
    fp1 = fopen("./files/Sync.com/installEmail.txt", "r");
    fseek(fp1,16,SEEK_SET);
    fscanf(fp1, "%s", str1);
    strcpy(sdInstall.email,str1);

    FILE *fp2;
    fp2 = fopen("./files/Sync.com/installStorage.txt", "r");

    j=0;
    while(i<32)
    {

        temp[j++]=fgetc(fp2);
        i++;
    }
    temp[j]='\0';
    strcpy(sdInstall.location,temp);

    j=0;
    while(i<41)
    {
        temp[j++]=fgetc(fp2);
        i++;
    }
    temp[j]='\0';
    strcpy(sdInstall.name,temp);

    printf("Installation Email ID:\t\"%s\"\n",sdInstall.email);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Installation Location:\t\"%s\"\n",sdInstall.location);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Installation Name    :\t\"%s\"\n",sdInstall.name);
    printf("------------------------------------------------------------------------------\n");
    printf("\n================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>Installation Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n");

}

void SyncLogin()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<Login Analysis of Sync.com>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str[250];
    char temp[50];
    int i=0,j=0,k=0;
    int flag=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' | grep -m 1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+220));

    if (cmd != NULL)
    {

        //EXTRACT INSTALL EMAIL ID FROM SOURCE.TXT IN FILE INSTALL EMAIL
        strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o \"username[a-zA-Z].*@.*displayname\"> ./files/Sync.com/login.txt");
                                                                 //username[start with an alphabet]*@*displayname
        system(cmd);
    }

    //READ FILE LOGIN.TXT IN TO A STRING
    FILE *fp;
    fp = fopen("./files/Sync.com/login.txt", "r");
    fgets(str, 250, fp);


    //FIND INDEX OF USER NAME IN THE STRING AND INCREMENT BY 8
    i=FindIdx(str,"username");

    i+=8;
    j=0;

    //START READING THE STRING FROM THE END OF USER NAME TILL SECOND . AFTER @
    while(1)
    {
        if(str[i]=='@'){
            flag=1;
        }
        if(str[i]=='.' && flag==1){
            j++;
            if(j==2) break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(sdlogin.username,temp);
    strcpy(sdlogin.displayname,temp);

    //FIND INDEX OF DEVICE NAME IN THE STRING AND INCREMENT BY 10
    i=FindIdx(str,"devicename");

    i+=10;
    flag=0;
    k=0;

    //START READING THE STRING FROM THE END OF DEVICE NAME TILL "|
    while(1){
        if(str[i]=='"' && str[i+1]=='|'){
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(sdlogin.devicename,temp);

    //RETRIEVING SERVER URL AND OTHER DETAILS
    //strcpy(cmd,"hexdump -v -e '\"%010_ad |\" 1024/1 \"%_p\"\"|\\n\"' -s 4344002895 -n 4k /run/media/root/hpDrive/SDdownload.dd | grep -E -o -m1 \".\{0,42\}command=emailexists.*): \">./files/Sync.com/loginUrl.txt");
    strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o \".\{0,42\}command=emailexists.*): \">./files/Sync.com/loginUrl.txt");


    system(cmd);

    //READ FILE LOGIN.TXT IN TO A STRING

    fp = fopen("./files/Sync.com/loginUrl.txt", "r");
    fgets(str, 250, fp);


    //EXTRACTING URL
    i=FindIdx(str,"emailexists");
    i+=11;
    j=i-53;
    k=0;

    while(j<i){
        temp[k++]=str[j++];
    }
    temp[k]='\0';
    strcpy(sdlogin.url,temp);

    //EXTRACTING DTS
    i=FindIdx(str,"net");
    j=i-25;
    k=0;

    while(j<i-1){
        temp[k++]=str[j++];
    }
    temp[k]='\0';
    strcpy(sdlogin.time,temp);

    //RETRIEVING USER ID AND DEVICE ID
    strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o  \".\{0,42\}command=batchdelete.*): \">./files/Sync.com/delete.txt");

    system(cmd);

    //READ FILE LOGIN.TXT IN TO A STRING
    fp = fopen("./files/Sync.com/delete.txt", "r");
    fgets(str, 250, fp);


    //EXTRACTING USER ID
    i=FindIdx(str,"userid");
    i+=7;
    k=0;

    while(1){
        if(str[i]=='&'){
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(sdlogin.userID,temp);

    //EXTRACTING DEVICE ID
    i=FindIdx(str,"deviceid");
    i+=9;
    k=0;

    while(1){
        if(str[i]=='&'){
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(sdlogin.deviceID,temp);

    printf("User Name   :\t\"%s\"\n",sdlogin.username);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Display Name:\t\"%s\"\n",sdlogin.displayname);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Device Name :\t\"%s\"\n",sdlogin.devicename);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("User ID     :\t\"%s\"\n",sdlogin.userID);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Device ID   :\t\"%s\"\n",sdlogin.deviceID);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Login Time  :\t\"%s\"\n",sdlogin.time);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Login Url   :\t\"%s\"\n",sdlogin.url);
    printf("------------------------------------------------------------------------------\n");

    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Login Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n");
}

void SyncUpload()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<Upload Analysis of Sync.com>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str[250];
    char temp[50];
    int i=0,j=0,k=0;
    int flag=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /run/media/root/hpDrive/SDdownload.dd | grep -m 1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));
    if (cmd != NULL)
    {
        //UPLOADED FILES
        strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o \"\.[a-zA-Z].*\....\.[0-9]\{16\}\.chunk\">./files/Sync.com/uploadFile.txt");
        system(cmd);  //COMMAND EXECUTED SUCCESSFULLY

        //UPLOADED URL
        strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o \".\{0,42\}command=uploadmultichunk.*):\">./files/Sync.com/uploadUrl.txt");
        system(cmd);  //COMMAND EXECUTED SUCCESSFULLY

        //UPLOADED PATH
        strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o \"/storage/emulated/0/.\{0,60\}\">./files/Sync.com/uploadPath.txt");


        system(cmd);  //COMMAND EXECUTED SUCCESSFULLY
    }

    //READ FILE UPLOAD.TXT IN TO A STRING
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("./files/Sync.com/uploadFile.txt", "r");
    fp2 = fopen("./files/Sync.com/uploadPath.txt", "r");
    fp3 = fopen("./files/Sync.com/uploadUrl.txt", "r");

    while(!feof(fp1))
    {
        fgets(str, 250, fp1);

        //LOOK FOR FILE NAME
        i=FindIdx(str,".chunk");

        if(i>0){
            //START READING THE NAME OF FILE
            j=strlen(str)-25;
            k=0;
            while(k<j){
                temp[k]=str[k+1]; //SKIP THE FIRST CHARACTER OF STR
                k++;
            }
            temp[k]='\0';
            strcpy(sdUpload.filename,temp);

            //LOOK FOR THE PATH OF IDENTIFIED FILE IN UPLOAD PATH.TXT
            while(!feof(fp2)){
                fgets(str, 250, fp2);

                //LOOK FOR PATH NAME
                strcpy(temp,"/");
                strcat(temp,sdUpload.filename);

                i=0;
                i=FindIdx(str,temp);
                if(i>0){
                    //START READING THE PATH OF FILE
                    j=i;
                    k=0;
                    while(k<j){
                        temp[k]=str[k]; //SKIP THE FIRST CHARACTER OF STR
                        k++;
                    }
                    temp[k]='\0';
                    strcpy(sdUpload.path,temp);
                }

            } //PATH NAME DONE
        }
    }//FILE NAME DONE

    //EXTRACT UPLOAD URL
    while(!feof(fp3)){
        fgets(str, 250, fp3);

        i=0;
        i=FindIdx(str,"uploadmultichunk");

        if(i>0)
        {

            i+=16;
            j=i-62;
            k=0;

            while(j<i){
                temp[k++]=str[j++];
            }
            temp[k]='\0';
            strcpy(sdUpload.url,temp);

            //READ JUST ONCE
            break;
        }
    } //DISPLAYING URL DONE

    printf("Uploaded File:\t\"%s\"\n",sdUpload.filename);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Upload Folder:\t\"%s\"\n",sdUpload.path);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Upload Url   :\t\"%s\"\n",sdUpload.url);
    printf("------------------------------------------------------------------------------\n");

    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Upload Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n");
}

void SyncDownload(){
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<Download Analysis of Sync.com>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str[250];
    char str2[150];
    char temp[50];
    int i=0,j=0,k=0;
    int flag=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /run/media/root/hpDrive/SDdownload.dd | grep -m 1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    if(cmd!=NULL){
        //EXTRACT ALL THE PATHNAMES FROM SOURCE.TXT IN FILE DOWNLOAD PATH
        strcpy(cmd,"cat ./files/Sync.com/source.txt|grep -E -o \"/storage/emulated/0/Download/[A-Za-z\_][A-Za-z0-9\-]*\.[a-zA-Z]*\">./files/Sync.com/downloadPath.txt");
        system(cmd);

        //EXTRACT ALL THE CLOUD DOWNLOADED FILES FROM SOURCE.TXT IN FILE DOWNLOAD
        strcpy(cmd,"cat ./files/Sync.com/source.txt|grep -E -o \"application/[a-z]\{3\}[a-zA-Z0-9]*Download\">./files/Sync.com/downloadFile.txt");
        system(cmd);
    }

    FILE *fp1,*fp2;
    fp1 = fopen("./files/Sync.com/downloadPath.txt", "r");


    //READ THE FILE DOWNLOAD PATH LINE BY LINE

    while(!feof(fp1)){

        fgets(str, 250, fp1);
        //LOOK FOR PATH NAME

        i=0;k=0;
        i=strlen(str);
        i--;    //SKIP THE NULL CHARACTER AT THE END OF STRING

        //EXTRACT FORMAT FROM THE END
        while(str[i]!='.'){
            temp[k++]=str[i--];
        }
        temp[k]='\0';
        strrev(temp);

        strcpy(sdDload.format,temp);
        sdDload.format[strlen(sdDload.format)-1]='\0';

        //EXTRACT FILEMANE FROM PATH STARTING FROM THE END
        j=FindIdx(str,"Download")+8;
        i--;k=0;
        while(i>j){
            temp[k++]=str[i--];
        }
        temp[k]='\0';
        strrev(temp);
        strcpy(sdDload.filename,temp);

        //EXTRACT PATHNAME
        k=0;
        while(i>0){
            temp[k++]=str[i--];
        }
        temp[k]='\0';
        strrev(temp);
        strcpy(sdDload.path,temp);

        //CHECK IF THE FILE IN DOWNLOAD FOLDER HAS A CORRESPONDING MATCH FROM CLOUD DOWNLOAD DEFINED BY DOWNLOADFILE.TXT
        //DETERMINE FORMAT AND DOWNLOAD ID
        //FOR EVERY FILE IDENTIFIED IN DOWNLOAD PATH LOCATE THE ENTRY IN DOWNLOAD FILE
        //IF MATCH FOUND DISPLAY THE FILE DETAILS ELSE SKIP
        fp2 = fopen("./files/Sync.com/downloadFile.txt", "r");
        strcpy(sdDload.downloadID,"0");

        while(!feof(fp2)){
            fgets(str2, 150, fp2);

            strcpy(temp,"/");

            i=FindIdx(str2,sdDload.filename);//LOOK FOR THE INDEX OF LEAR


             if(i>0){    //INDEX FOUND
                i+=strlen(sdDload.filename);
                j=FindIdx(str2,"Download");
                k=0;
                while(i<j){
                    temp[k++]=str2[i++];
                }
                temp[k]='\0';
                strcpy(sdDload.downloadID,temp);
                break;
            }
        }
        if(convertToInt(sdDload.downloadID)>0){



            printf("Filename   :\t\"%s\"\n",sdDload.filename);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Format     :\t\"%s\"\n",sdDload.format);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Pathname   :\t\"%s\"\n",sdDload.path);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Download ID:\t\"%s\"\n",sdDload.downloadID);
            printf("------------------------------------------------------------------------------\n");
        }
    }

    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>DownLoad Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n");
}

void SyncDelete()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<Delete Analysis of Sync.com>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char str[500];
    char temp[50];
    int i=0,j=0,k=0;

    //READ FILE DELETE.TXT IN TO A STRING
    FILE *fp;

    //READ FILE LOGIN.TXT IN TO A STRING
    fp = fopen("./files/Sync.com/delete.txt", "r");
    fgets(str, 500, fp);



    //EXTRACTING USER ID
    i=FindIdx(str,"userid");
    i+=7;
    k=0;

    while(1){
        if(str[i]=='&'){
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';

    printf("User ID       :\t\"%s\"\n",temp);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

    //EXTRACTING DEVICE ID
    i=FindIdx(str,"deviceid");
    i+=9;
    k=0;

    while(1){
        if(str[i]=='&'){
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';

    printf("Device ID     :\t\"%s\"\n",temp);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

//EXTRACTING QueryString
    i=FindIdx(str,"batchdelete");
    i+=11;
    j=i-53;
    k=0;

    while(j<i){
        temp[k++]=str[j++];
    }
    temp[k]='\0';

    printf("Delete Url    :\t\"%s\"\n",temp);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

    //DELETION DTS
    i=FindIdx(str,"net");
    j=i-25;
    k=0;

    while(j<i-1)
    {
        temp[k++]=str[j++];
    }
    temp[k]='\0';

    printf("Date Timestamp:\t\"%s\"\n",temp);
    printf("------------------------------------------------------------------------------\n");


    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>Delete Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n");
}

void SyncShare()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<Share Analysis of Sync.com>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");
    printf("------------------------------------------------------------------------------\n");

    char *cmd=NULL;
    char str[500];
    char temp[50],tempSdr[50];
    int i=0,j=0,k=0;
    int flag=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /run/media/root/hpDrive/SDdownload.dd | grep -m 1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    //FOR SERVER ATTACHMENTS
    if (cmd != NULL)
    {

        //EXTRACT INSTALL EMAIL ID FROM SOURCE.TXT IN FILE INSTALL EMAIL
        strcpy(cmd,"cat ./files/Sync.com/source.txt | grep -E -o \"content://com.sync.mobileapp.fileprovider.*<forensic.research2k18@gmail.com>\\\"\\\".*@.*.[a-z]{3}>.*\|SERVER_ATTACHMENT\">./files/Sync.com/shareAtt.txt");
                                                                 //username[start with an alphabet]*@*displayname
        system(cmd);
    }

    //DISPLAY FILES SHARED
    FILE *fp1;
    fp1 = fopen("./files/Sync.com/shareAtt.txt", "r");


    //READ THE FILE SHARED FILES LINE BY LINE

    while(!feof(fp1))
    {

        //Clear the Share Datastructure
        strcpy(sdShare.attachmentID,"");
        strcpy(sdShare.date,"");
        strcpy(sdShare.filename,"");
        strcpy(sdShare.format,"");
        strcpy(sdShare.receiver,"");
        strcpy(sdShare.sender,"");
        strcpy(sdShare.size,"");
        strcpy(sdShare.time,"");
        strcpy(sdShare.type,"");
        strcpy(sdShare.url,"");

        //STORE SENDER EMAIL ID
        strcpy(sdShare.sender,sdInstall.email);
        strcpy(tempSdr,sdInstall.email);
        strcat(tempSdr,">");

        fgets(str, 500, fp1);
        //printf("String Read = %s\n Pattern =%s\n",str,tempSdr);


        i=0;j=0;k=0;

        //Check for Server Attachments
        if(FindIdx(str,"SERVER_ATTACHMENT")>0)
        {
            //STORE FILE TYPE
            strcpy(sdShare.type,"SERVER_ATTACHMENT");

            i=FindIdx(str,tempSdr);

            i+=strlen(sdShare.sender);

            //increment the index to reach to first character of receiver after <
            i+=5;
            //printf("%d at %c is index length\n",i,str[i]);

            //extract the receivers name that exists till >
            while(str[i]!='>')
            {
                temp[k++]=str[i++];
            }
            temp[k]='\0';
            strcpy(sdShare.receiver,temp);

            //move to next extraction point ie filename
            while(str[i]!='|')
            {
                i++;
            }

            //start reading the filename
            k=0;
            i++;
            while(str[i]!='|')
            {
                temp[k++]=str[i++];
            }
            temp[k]='\0';
            strcpy(sdShare.filename,temp);

            //start reading the format
            k=0;
            i++;
            while(str[i]!='|')
            {
                temp[k++]=str[i++];
            }
            temp[k]='\0';
            strcpy(sdShare.format,temp);

            //start reading the file size
            k=0;
            i++;
            while(str[i]!='|')
            {
                temp[k++]=str[i++];
            }
            temp[k]='\0';
            strcpy(sdShare.size,temp);

            //Read Attachment ID and Time
            i=FindIdx(str,".attachment")-1;

            //start reading the attachment ID
            k=0;
            i;
            while(str[i]!='-')
            {
                temp[k++]=str[i--];
            }
            temp[k]='\0';
            strrev(temp);
            strcpy(sdShare.attachmentID,temp);

            //start reading the Time
            k=0;
            i--;
            while(str[i]!='-')
            {
                temp[k++]=str[i--];
            }
            temp[k]='\0';
            strrev(temp);
            strcpy(sdShare.time,temp);

            //start reading the Time
            k=0;
            i--;
            while(str[i]!='/')
            {
                temp[k++]=str[i--];
            }
            temp[k]='\0';
            strrev(temp);
            strcpy(sdShare.date,temp);

            //DISPLAY THE RESULTS
            printf("Filename    :\t\"%s\"\n",sdShare.filename);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Format      :\t\"%s\"\n",sdShare.format);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Size        :\t\"%s\"\n",sdShare.size);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Shared As   :\t\"%s\"\n",sdShare.type);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("AttachmentID:\t\"%s\"\n",sdShare.attachmentID);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Shared Time :\t\"%s\"\n",sdShare.time);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Shared Date :\t\"%s\"\n",sdShare.date);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Sender      :\t\"%s\"\n",sdShare.sender);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Receiver    :\t\"%s\"\n",sdShare.receiver);
            printf("------------------------------------------------------------------------------\n");
        }
        //Check for files shared as links
        else if(FindIdx(str,"https://cp.sync.com/dl/")>0){
            //printf("LINK FOUND\n");

            //STORE FILE TYPE
            strcpy(sdShare.type,"SERVER_LINK");

            i=FindIdx(str,tempSdr);

            i+=strlen(sdShare.sender);

            //increment the index to reach to first character of receiver after <
            i+=5;

            //extract the receivers name that exists till >
            while(str[i]!='>')
            {
                temp[k++]=str[i++];
            }
            temp[k]='\0';
            strcpy(sdShare.receiver,temp);

            i=FindIdx(str,"https://cp.sync.com/dl/");
            i+=23;
            strcpy(sdShare.url,"https://cp.sync.com/dl/");

            k=0;
            while(str[i]!='.')
            {
                temp[k++]=str[i++];
            }
            temp[k-1]='\0';
            strcat(sdShare.url,temp);

            printf("Shared As   :\t\"%s\"\n",sdShare.type);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Sender      :\t\"%s\"\n",sdShare.sender);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Receiver    :\t\"%s\"\n",sdShare.receiver);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("Share Link  :\t\"%s\"\n",sdShare.url);
            printf("------------------------------------------------------------------------------\n");

        }
    }

    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>Share Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n");
}





void FlipDriveForensics()
{

    printf("\n\n\n-------------------------------------------------------------------------------\n");
    printf("    --------    --------    --------------------    --------    --------       \n");
    printf("    <<<<<<<<    <<<<<<<<    FLIP DRIVE FORENSICS    >>>>>>>>    >>>>>>>>       \n");
    printf("    --------    --------    --------------------    --------    --------       \n");
    printf("-------------------------------------------------------------------------------\n");
    char *cmd=NULL;
    char *cmd2=NULL;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /run/media/root/hpDrive/SDdownload.dd | grep -m 1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));
    cmd2 = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /run/media/root/hpDrive/SDdownload.dd | grep -m 1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));


    if (cmd != NULL && cmd2 != NULL)
    {
        //COMMAND FOR DOWNLOAD ANALYSIS */
        strcpy(cmd,"hexdump -v -e '\"%010_ad |\" 4096/1 \"%_p\"\"|\\n\"' /run/media/root/TOSHIBA03/FDall01.dd | grep -E -o \"accountInfo\{.*first_name.*\}|<package name=\\\"com.flipdrive.*insta|https://api2.flipdrive.*content\">./files/Flipdrive/source.txt");


        strcpy(cmd2,"hexdump -v -e '\"%010_ad | \" 4096/1 \"%_p\"\"\\n\"' -s 2590767938 -n 4096 /run/media/root/TOSHIBA03/FDall01.dd | grep -E -o \".\{1000\}My Music.*My Documents\">./files/Flipdrive/mainsource.txt");

        system(cmd2);  //COMMAND EXECUTED SUCCESSFULLY
    }

    FlipDriveInstall();
    getchar();

    FlipDriveLogin();
    getchar();

    FlipDriveupload();
    getchar();

    FlipDriveDownload();
    getchar();

    FlipDriveDelete();
    getchar();
}



void FlipDriveLogin()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<Login Analysis of FlipDrive>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str[600];
    char temp[50];
    int i=0,j=0,k=0;
    int flag=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /media/sajidsajad/research/SDdownload.dd | grep -m1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    if (cmd != NULL)
    {

        strcpy(cmd,"cat ./files/Flipdrive/source.txt | grep -E -o \"accountInfo\{.*\}\"> ./files/Flipdrive/login.txt");                                                       //username[start with an alphabet]*@*displayname
        system(cmd);
    }

    //READ FILE LOGIN.TXT IN TO A STRING
    FILE *fp;
    fp = fopen("./files/Flipdrive/login.txt", "r");
    fgets(str, 500, fp);


    //FIND INDEX OF FIRST NAME IN THE STRING AND INCREMENT BY 13
    i=FindIdx(str,"first_name");

    i+=13;
    j=0;

    //reading till " so as to notify end of first name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(fdlogin.firstName,temp);



    //FIND INDEX OF LATST NAME IN THE STRING AND INCREMENT BY 13
    i=FindIdx(str,"last_name");

    i+=12;
    j=0;
    k=0;

    //reading till " so as to notify end of last name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(fdlogin.lastName,temp);




     //FIND INDEX OF USER NAME IN THE STRING AND INCREMENT BY 13
    i=FindIdx(str,"user");

    i+=7;
    j=0;
    k=0;

    //reading till " so as to notify end of last name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(fdlogin.user, temp);



    // FINDING INDEX OF ACCOUNT_HASH
    i=FindIdx(str,"account_hash");

    i+=15;
    j=0;
    k=0;

    //reading till " so as to notify end of last name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(fdlogin.accountHash, temp);



    // FINDING INDEX OF USER HASH IN FILE LOGIN.TXT
    i=FindIdx(str,"user_hash");

    i+=12;
    j=0;
    k=0;

    // read till " which notify end of user hash
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
        //printf("%c",str[i]);
    }
    temp[k]='\0';
    strcpy(fdlogin.userHash,temp);



    //FINDING INDEX OF ACCOUNT SIZE
    i=FindIdx(str,"account_size");

    i+=15;
    j=0;
    k=0;

    //reading till " so as to notify end of last name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
        //printf("%c",str[i]);
    }
    temp[k]='\0';
    strcpy(fdlogin.accountSize, temp);



	//FINDING INDEX OF EMAIL ID
    i=FindIdx(str,"email");

    i+=8;
    j=0;
    k=0;
    flag = 0;

    //START READING THE STRING FROM THE END OF USER NAME TILL SECOND . AFTER @
    while(1)
    {
        if(str[i]== '"')
        {
            break;
        }
        if(str[i]=='@')
        {
            flag=1;
        }
        if(str[i]=='.' && flag==1)
        {
            j++;
            if(j==2) break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(fdlogin.email,temp);


	printf("First Name      :\t\"%s\"\tLast Name    :\t\"%s\"\n",fdlogin.firstName, fdlogin.lastName);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("User            :\t\"%s\"\n",fdlogin.user);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("Account Hash    :\t\"%s\"\n",fdlogin.accountHash);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("User Hash       :\t\"%s\"\n",fdlogin.userHash);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("Account Size    :\t\"%s\"\n",fdlogin.accountSize);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Login Email Id  :\t\"%s\"\n",fdlogin.email);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");


    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Login Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n\n\n");
}




FlipDriveInstall()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<Installation Analysis of FlipDrive>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str[600];
    char temp[50];
    char path[200];
    int i=0,j=0,k=0;
    int flag=0;


    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /media/sajidsajad/research/SDdownload.dd | grep -m1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    if (cmd != NULL)
    {

        //EXTRACT INSTALL EMAIL ID FROM SOURCE.TXT IN FILE INSTALL EMAIL
        strcpy(cmd,"cat ./files/Flipdrive/source.txt | grep -E -o \"<package name=\\\"com.flipdrive.*insta\"> ./files/Flipdrive/install.txt");                                                       //username[start with an alphabet]*@*displayname
        system(cmd);
    }


    //READ FILE INSTALL.TXT IN TO A STRING
    FILE *fp;
    fp = fopen("./files/Flipdrive/install.txt", "r");
    fgets(str, 500, fp);


    //FIND INDEX OF PACKAGE NAME IN THE STRING AND INCREMENT BY 13
    i=FindIdx(str,"package name");

    i+=14;
    j=0;

    //reading till " so as to notify end of first name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
        //printf("%c",str[i]);
    }
    temp[k]='\0';
    strcpy(fdinstall.packageName,temp);



    //FIND INDEX OF Code PATH IN THE STRING AND INCREMENT BY 13
    i=FindIdx(str,"codePath");

    i+=10;
    j=0;
    k=0;

    //reading till " so as to notify end of first name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(fdinstall.codePath,temp);


     //FIND INDEX OF Native LIBRARY IN THE STRING AND INCREMENT BY 13
    i=FindIdx(str,"nativeLibraryPath");

    i+=19;
    j=0;
    k=0;

    //reading till " so as to notify end of first name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(fdinstall.nativeLibrary,temp);

     //FIND INDEX OF USER ID IN THE STRING AND INCREMENT BY 13
    i=FindIdx(str,"userId");

    i+=8;
    j=0;
    k=0;

    //reading till " so as to notify end of first name
    while(1)
    {
        if(str[i]=='"')
        {
            break;
        }
        temp[k++]=str[i++];
    }
    temp[k]='\0';
    strcpy(fdinstall.userID,temp);

    printf("Package Name        :\t\"%s\"\n",fdinstall.packageName);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Code Path           :\t\"%s\"\n",fdinstall.codePath);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Native Library Path :\t\"%s\"\n",fdinstall.nativeLibrary);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("User Id             :\t\"%s\"\n",fdinstall.userID);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Installation Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n");


}


FlipDriveDelete()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<Delete Analysis of FlipDrive>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str[500];
    char temp[500];
    char path[200];
    int i=0,j=0,k=0;
    int flag=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /media/sajidsajad/research/SDdownload.dd | grep -m1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    if (cmd != NULL)
    {

        //EXTRACT INSTALL EMAIL ID FROM SOURCE.TXT IN FILE INSTALL EMAIL
        strcpy(cmd,"cat ./files/Flipdrive/mainsource.txt | grep -E -o \".\{1000\}My Music.*My Documents\">./files/Flipdrive/delete.txt");                                                       //username[start with an alphabet]*@*displayname
     //   printf("\n<<<Executing Command on Shell>>>\n %s\n",cmd);
        system(cmd);
       // printf("\n------------------------------------------------------------------------------\n");
    }


    //READ FILE INSTALL.TXT IN TO A STRING
    FILE *fp;
    fp = fopen("./files/Flipdrive/delete.txt", "r");
    fgets(str, 300, fp);

    //FIND INDEX OF PACKAGE NAME IN THE STRING AND INCREMENT BY 13
    i=FindIdx(str,"fileNonetrash");
    if(i == 0)
    {
        printf("No Records Found, Try Again!\n");
    }
    else
    {
        i+=13;
        j=0;


        //reading till " so as to notify end of first name
        while(1)
        {
            if(str[i]=='.')
            {
                while(j<=3)
                {
                    temp[k++] = str[i++];
                    j++;
                }
            }
            if(j>3)
            {
                break;
            }
            temp[k++]=str[i++];
        }
        temp[k]='\0';
        strcpy(fddelete.deletedFile,temp);

        j=i+31;
        k=0;

        while(1)
        {
            if(i>j)
            {
                break;
            }
            temp[k++] = str[i++];
        }
        temp[k] = '\0';
        strcpy(fddelete.deletedFileUserHash,temp);


        k=0;

        while(1)
        {
           if(str[i] == ' ')
            {
                break;
            }
            temp[k++] = str[i++];
        }
        temp[k] = '\0';
        strcpy(fddelete.deletedFileFirstName, temp);

        k=0;
        i++;

        while(1)
        {
            if(str[i] == '[')
            {
                break;
            }
            temp[k++] = str[i++];

        }
        temp[k] = '\0';
        strcpy(fddelete.deletedFileLastName, temp);



        printf("Deleted File                :\t\"%s\"\n",fddelete.deletedFile);
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("First Name                  : \t\"%s\"  Last Name:      \t\"%s\"\n", fddelete.deletedFileFirstName, fddelete.deletedFileLastName);
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("User Hash of Deleted File   : \t\"%s\"\n",fddelete.deletedFileUserHash);
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");


        printf("================================================================================\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Delete Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("================================================================================\n\n\n\n\n\n");
    }


}
FlipDriveupload()
{
    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<Upload Analysis of FlipDrive>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str[500];
    char temp[100], temp2[100];
    char name[20];
    char path[200];
    int i=0,j=0,k=0;
    int flag=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /media/sajidsajad/research/SDdownload.dd | grep -m1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    if (cmd != NULL)
    {

        strcpy(cmd,"cat ./files/Flipdrive/mainsource.txt | grep -E -o \".\{1000\}My Music.*My Documents\">./files/Flipdrive/upload.txt");
        system(cmd);
    }
    FILE *fp;
    fp = fopen("./files/Flipdrive/upload.txt", "r");
    fgets(str, 400, fp);

    i=FindIdx(str,"file:");
    i+=7;

    while(str[i] != '.')
    {
        temp[k++] = str[i++];
    }
    while(j<=3)
    {
        temp[k++] = str[i++];
        j++;
    }
    temp[k] = '\0';
    strcpy(fdupload.uploadedFilePath, temp);


    j=strlen(temp);
    j--;
    k=0;
    while(temp[j]!= '/')
    {
        name[k++] = temp[j--];
    }
    name[k]= '\0';
    strrev(name);
    strcpy(fdupload.uploadedFile, name);


    name[strlen(name)-4] = '\0';

    temp2[0] = 0;
    strcat(temp2, "fileNonemain");
    strcat(temp2, name);
    temp2[strlen(temp2)] = '\0';

    k = 0;
    i = FindIdx(str,temp2);
    k = strlen(temp2);

    k = k+4;

    i = i+k;

    j = i+32;
    k = 0;
    while(1)
    {
        if(i>=j)
        {
            break;
        }
        temp[k++] = str[i++];
    }
    temp[k] = '\0';
    strcpy(fdupload.uploadedFileUserHash, temp);

    k = 0;
    while(1)
    {
        if(str[i] == ' ')
        {
            break;
        }
        temp[k++] = str[i++];

    }
    temp[k] = '\0';
    strcpy(fdupload.uploadedFileFirstName, temp);

    i++;
    k = 0;
    while(1)
    {
        if(str[i] == '[')
        {
            break;
        }
        temp[k++] = str[i++];

    }
    temp[k] = '\0';
    strcpy(fdupload.uploadedFileLastName, temp);

    printf("Uploaded File               :\t\"%s\"\n",fdupload.uploadedFile);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Storage Path of             : \t\"%s\"\n",fdupload.uploadedFilePath);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("First Name                  : \t\"%s\"  Last Name       :\t\"%s\"\n", fdupload.uploadedFileFirstName,  fdupload.uploadedFileLastName);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("User Hash of Uploaded File  : \t\"%s\"\n",fdupload.uploadedFileUserHash);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Upload Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n\n\n\n\n");

}



FlipDriveDownload()
{


    printf("================================================================================\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<Download Analysis of FlipDrive>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("================================================================================\n");

    char *cmd=NULL;
    char str[1000];
    char temp[100], temp2[100];
    char name[20];
    char path[200];
    int i=0,j=0,k=0;
    int flag=0;

    cmd = malloc (strlen("sudo hexdump -v -e '%010_ad | 512/1 %_p|\n' /media/sajidsajad/research/SDdownload.dd | grep -m1 -E -o username[a-zA-Z].*@.*displayname>./files/Sync.com/login.txt"+120));

    if (cmd != NULL)
    {

        strcpy(cmd,"cat ./files/Flipdrive/source.txt | grep -E -o \"https://api2.flipdrive.*content\">./files/Flipdrive/download.txt");
        system(cmd);


        strcpy(cmd,"cat ./files/Flipdrive/mainsource.txt | grep -E -o \".\{1000\}My Music.*My Documents\">./files/Flipdrive/download_temp.txt");
        system(cmd);
    }


    FILE *fp;
    fp = fopen("./files/Flipdrive/download.txt", "r");
    fgets(str, 400, fp);


    i=FindIdx(str,"file://");
    i+=7;

    while(str[i] != '.')
    {
        temp[k++] = str[i++];
    }
    while(j<=3)
    {
        temp[k++] = str[i++];
        j++;
    }
    temp[k] = '\0';
    strcpy(fddownload.downloadedFilePath, temp);



    j=strlen(temp);
    j--;
    k=0;
    while(temp[j]!= '/')
    {
        name[k++] = temp[j--];
    }
    name[k]= '\0';
    strrev(name);
    strcpy(fddownload.downloadedFile, name);

    FILE *fpp;
    fpp = fopen("./files/Flipdrive/download_temp.txt", "r");
    fgets(str, 900, fpp);

    i = FindIdx(str,name);
    k= 0;
    k = strlen(name);
    i = i+k;

    k = 0;
    j = i+32;
    while(1)
    {
        if(i >=j)
        {
            break;
        }
        temp[k++] = str[i++];

    }
    temp[k] = '\0';
    strcpy(fddownload.downloadedFileUserHash, temp);

    k = 0;
    while(1)
    {
        if(str[i] == ' ')
        {
            break;
        }
        temp[k++] = str[i++];

    }
    temp[k] = '\0';
    strcpy(fddownload.downloadedFileFirstName, temp);


    i++;
    k = 0;
    while(1)
    {
        if(str[i] == '[')
        {
            break;
        }
        temp[k++] = str[i++];

    }
    temp[k] = '\0';
    strcpy(fddownload.downloadedFileLastName, temp);



    printf("Downloaded File             :\t\"%s\"\n",fddownload.downloadedFile);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Storage Path of             : \t\"%s\"\n",fddownload.downloadedFilePath);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("First Name                  : \t\"%s\"  Last Name       :\t\"%s\"\n", fddownload.downloadedFileFirstName,  fddownload.downloadedFileLastName);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("User Hash of Uploaded File  : \t\"%s\"\n",fddownload.downloadedFileUserHash);
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

    printf("================================================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>Download Analysis Complete<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("================================================================================\n\n");

}





int FindIdx(char* str,char* word){
    int i, index, found = 0;




    /* Run loop from start to end of string */
    index = 0;
    while(str[index] != '\0')
    {

        /* If first character of word matches with the given string */
        if(str[index] == word[0])
        {
            /* Match entire word with current found index */
            i=0;
            found = 1;
            while(word[i] != '\0')
            {
                if(str[index + i] != word[i])
                {
                    found = 0;
                    break;
                }

                i++;
            }
        }

        /* If the word is found then get out of loop */
        if(found == 1)
        {
            break;
        }

        index++;
    }

    /*  Print success message if the word is found */
    if(found == 1)
    {
    }
    else
    {
        index=0;
    }

    return index;
}

void strrev(char *str){
    char *temp;
    int len = strlen(str);
    int i,k;
    k=len-1;

    temp=(char*)malloc(sizeof(len+1));

    for(i = 0; i < len; i++)
    {
        temp[i] = str[k];
        k--;
    }
    temp[i]='\0';
    strcpy(str,temp);
}

//CONVERTS CHARACTER STRING VALUES TO THEIR CORRESPONDING DECIMAL VALUES
int convertToInt(char *val){
    int ret;

    sscanf(val, "%d", &ret);
    //printf("Value converted from %s to %d\n",val,ret);
    return ret;
}





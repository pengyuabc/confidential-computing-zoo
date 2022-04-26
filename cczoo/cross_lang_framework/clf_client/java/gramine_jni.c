#include "GramineJni_gramine_jni.h"

#define int8_t jbyte
#define int32_t jint
#define int64_t jlong

int get_key(int8_t* key, int32_t key_len);
int get_file_2_buff(char* fname, int64_t offset, int8_t* data, int32_t len, int32_t* ret_len);
int get_file_size(char* fname, int64_t* ret_len);
int put_result(char* fname, int64_t offset, int8_t* data, int32_t len);


/*
 * Class:     GramineJni_gramine_jni
 * Method:    get_key
 * Signature: ([BI)I
 */
JNIEXPORT jint JNICALL Java_GramineJni_gramine_1jni_get_1key
  (JNIEnv *env, jobject obj, jbyteArray key, jint key_len) {
	jbyte* bufferPtr = (*env)->GetByteArrayElements(env, key, NULL);
	int ret = get_key(bufferPtr, key_len);
	(*env)->ReleaseByteArrayElements(env, key, bufferPtr, 0);
	return ret;
}

/*
 * Class:     GramineJni_gramine_jni
 * Method:    get_file_2_buff
 * Signature: ([BJ[BJ[J)I
 */
JNIEXPORT jint JNICALL Java_GramineJni_gramine_1jni_get_1file_12_1buff
  (JNIEnv *env, jobject obj, jbyteArray fname, jlong offset, jbyteArray data, jint len, jintArray ret_len) {
	jbyte* fnamePtr = (*env)->GetByteArrayElements(env, fname, NULL);
	jbyte* dataPtr = (*env)->GetByteArrayElements(env, data, NULL);
	jbyte* ret_lenPtr = (*env)->GetByteArrayElements(env, ret_len, NULL);

	int ret = get_file_2_buff((char*)fnamePtr, offset, dataPtr, len, (jint*)ret_lenPtr);

	(*env)->ReleaseByteArrayElements(env, fname, fnamePtr, 0);
	(*env)->ReleaseByteArrayElements(env, data, dataPtr, 0);
	(*env)->ReleaseByteArrayElements(env, ret_len, ret_lenPtr, 0);
	return ret;
}

/*
 * Class:     GramineJni_gramine_jni
 * Method:    get_file_size
 * Signature: ([B[J)I
 */
JNIEXPORT jint JNICALL Java_GramineJni_gramine_1jni_get_1file_1size
  (JNIEnv *env, jobject obj, jbyteArray fname, jlongArray ret_len) {
	jbyte* fnamePtr = (*env)->GetByteArrayElements(env, fname, NULL);
	jbyte* ret_lenPtr = (*env)->GetByteArrayElements(env, ret_len, NULL);

	int ret = get_file_size((char*)fnamePtr, (jlong*)ret_lenPtr);

	(*env)->ReleaseByteArrayElements(env, fname, fnamePtr, 0);
	(*env)->ReleaseByteArrayElements(env, ret_len, ret_lenPtr, 0);
	return ret;
}

/*
 * Class:     GramineJni_gramine_jni
 * Method:    put_result
 * Signature: ([BJ[BI)I
 */
JNIEXPORT jint JNICALL Java_GramineJni_gramine_1jni_put_1result
  (JNIEnv *env, jobject obj, jbyteArray fname, jlong offset, jbyteArray data, jint len) {
	jbyte* fnamePtr = (*env)->GetByteArrayElements(env, fname, NULL);
	jbyte* dataPtr = (*env)->GetByteArrayElements(env, data, NULL);

	int ret = put_result((char*)fnamePtr, offset, dataPtr, len);

	(*env)->ReleaseByteArrayElements(env, fname, fnamePtr, 0);
	(*env)->ReleaseByteArrayElements(env, data, dataPtr, 0);
	return ret;
}


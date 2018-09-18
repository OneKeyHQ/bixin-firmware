# Automatically generated by pb2py
# fmt: off
import protobuf as p


class LiskVerifyMessage(p.MessageType):
    MESSAGE_WIRE_TYPE = 120

    def __init__(
        self,
        public_key: bytes = None,
        signature: bytes = None,
        message: bytes = None,
    ) -> None:
        self.public_key = public_key
        self.signature = signature
        self.message = message

    @classmethod
    def get_fields(cls):
        return {
            1: ('public_key', p.BytesType, 0),
            2: ('signature', p.BytesType, 0),
            3: ('message', p.BytesType, 0),
        }
